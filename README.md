# Pioneer Rocketry Flight Computer V3

## Hardware

### Sensors/IC's
- Main MCU: STM32H745
- High G Accel: H3LIS100
- Low G Accel: AIS3624
- Gyro: I3G4250
- Magnetometer: MMC5603
- Barometer: MS560702BA03-50
- GPS: SAM-M8Q
- Thermocouple: MCP96L00T
- ADC: ADS1232

### Other Hardware Features
- 5 Pyro Channels
- 2 Switch 5v Rails
- 2 Switch Battery Rails
- MicroSD Card
- I2C, SPI Breakout
- 6 Servos
- Lora SX1262 Radio as Breakout Boards

## Software
- 3 Dof Kalman Filter for Position Estimation
- Live Telemetery
- *Active Control* (Long term project to keep rocket pointing up)
- Staging Logic/Inflight Events
- Software will be written in c++ using [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)

### Software Flow States
- Boot and Inital System Check
- Kalman Filter Localization
- Preflight checks
- Flight Loop
    - Sensor Fusion
    - *PID Control* (active control)
    - Telemetry
    - Inflight Events
- Landing

### State Machine/Flow
The software will be a (mostly) linear state machine.
```mermaid
stateDiagram-v2
    [*] --> PreLaunch

    state PreLaunch {
        direction LR
        [*] --> Booting
        Booting --> Checks
        Checks --> Localizing
        Localizing --> Ready
    }

    PreLaunch --> Flight : Armed

    state Flight {
        direction LR
        [*] --> Accelerating
        Accelerating --> Ascending
        Accelerating --> Landed
        Ascending --> Accelerating : Multistage Rocket
        Ascending --> Descending
        Descending --> Landed
        Descending --> Drouge
        Drouge --> Landed
        Drouge --> Main
        Main  --> Landed
    }

    state Landed {
        [*]
    }
```

The state machine can fo from Coasting up to Accelerating if its a multistage rocket. It can also skip states incase of any failures.

Also note that standard orientation solving doesn't work while the rocket is accelerating, where we will have to use intergration of angular velocity.

### Core Processes
| CM7 | CM4|
|--|--|
| Data collection | State Machine |
| Kalman Filter | Radio |
|  | Control/Events |

### Testing

#### Hardware-in-the-loop Testing (HILT)
HILT uses "fake" sensor readings to simulate a flight.
This is done by plugging it into a computer, and sending it data via USB/Serial, and having it pretend like its flying

#### Flight Tests
Flights are going to start out basic by just trying to quantify where the rocket is, and how fast. As well as testing state transitions. \
After every successful flight we can add more features like testing parachute deployment, then 2nd stage deployment ignition, then control. \
We also need to test it in high Speed and high G flights.


### AHRS and Position Estimation
Attitude and Heading Reference System (AHRS) On the ground and after motor burnout we can use either Mahony filter or Madgwick filters. While the motor is buring we can use either of the filters without the accelerometer correction. Can also just intergrate angular velocity to get the Attitude.\
We should use a Quaterinion to represent the Attitude.
When we convert to or from euler angles we will use Local East, North, Up. (ENU). \
Where X is east, Y is north, and Z is up. Roll is a rotation around the Z axis, pitch is a rotation around the X axis, and yaw is a rotation around the Y axis.

Position Estimation uses an Async Kalman Filter. \
Then taking accelerometer reading from both IMU, and rotates them based on the Attitude from the AHRS system.
The Kalman Filter finds the best estimation of the position using the accelerometer readings, and GPS readings.

#### New Idea

I think we can get away with using a basic Complementary Filter while on the ground, but once we launch we switch to just intergrating angular velocity.\
But we need a accurate measurement of the Gyro Bias, and Gyro Drift 

Then you can rotate the accelerometer readings by the attitude, and integrate them to get the position (up until apogee).

#### Integration quaternion
To integration a quaternion with euler angular velocities you can [use this](https://stackoverflow.com/a/24201879)

```cpp
Quaternion deltaRotation(Vector3& angVel, double deltaTime)
{
   Vector3 ha = angVel * (deltaTime * 0.5); // vector of half angle
   double l = ha.normalize(); // magnitude
   if (l > 0) {
      ha *= sin(l) / l;
   }
   return Quaternion(cos(l), ha.x(), ha.y(), ha.z());
}

orientation *= deltaRotation(anglularVelocity, deltaTime);
orientation.normalize();
```