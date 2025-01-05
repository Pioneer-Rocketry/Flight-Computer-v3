
#ifndef DATA_H
#define DATA_H

#include "datatypes/vector.h"

class Data {
    public:
        Data();

        void save();
        void log();

        // Raw sensor readings
        Vector H2LIS100_Accel; // H2LIS100 Accelerometer in m/s^2
        Vector AIS2624_Accel;  // AIS2624 Accelerometer in m/s^2

        Vector I3G4250_Gyro; // I3G4250 Gyroscope in degrees/s

        Vector MMC5603_Mag; // MMC5603 Magnetometer in uT

        Vector MS560702BA03_Pressure; // MS560702BA03 Pressure in hPa
};

#endif