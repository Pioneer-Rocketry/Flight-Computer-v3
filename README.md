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
- H-Bridge Motor Driver
- MicroSD Card
- I2C, SPI Breakout
- 6 Servos
- Lora SX1262 Radio

## Software
- 3 Dof Kalman Filter for Position Estimation
- Live Telemetery
- *Active Control* (Long term project to keep rocket pointing up)
- Staging Logic/Inflight Events

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
With states that include:
- Booting
- System Checks
- Localizing
- Armed
- Accelerating
- Coasting Up
- Apogee
- Descending
- Descending under Drouge Chute
- Descending under Main Chute
- Landed

The state machine can fo from Coasting up to Accelerating if its a multistage rocket. It can also skip states incase of any failures.

Also note that standard orientation solving doesn't work while the rocket is accelerating, where we will have to use intergration of angular velocity.


### Standards
- Classes should use `UpperCamelCase` capitalization
- Functions should use `lowerCamelCase` capitalization
- Variables should use `lowerCamelCase` capitalization
- Constants should use `CAPS_LOCK_SNAKE_CASE` capitalization
- Variables should be short and descriptive
    - example: posX
- Functions should have docstrings saying what each variable is, and what the output is.
- All git commits should have a message that talks about what was changed
