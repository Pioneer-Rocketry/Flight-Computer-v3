
#ifndef ACCEL_H3LIS100_H
#define ACCEL_H3LIS100_H

#include "sensors/sensors.hpp"

// Addresses
#define H3LIS100_ADDRESS1   0x18 // Address when SDO/AS0 is 0
#define H3LIS100_ADDRESS2   0x19 // Address when SDO/AS0 is 1

// Who Am I ID
#define H3LIS100_ID         0x32

// Register addresses
#define H3LIS100_WHO_AM_I           0x0F
#define H3LIS100_CTRL_REG1          0x20
#define H3LIS100_CTRL_REG2          0x21
#define H3LIS100_CTRL_REG3          0x22
#define H3LIS100_CTRL_REG4          0x23
#define H3LIS100_CTRL_REG5          0x24
#define H3LIS100_HP_FILTER_RESET    0x25
#define H3LIS100_REFERENCE          0x26
#define H3LIS100_STATUS_REG         0x27
#define H3LIS100_OUT_X              0x29
#define H3LIS100_OUT_Y              0x2B
#define H3LIS100_OUT_Z              0x2D
#define H3LIS100_INT1_CFG           0x30
#define H3LIS100_INT1_SRC           0x31
#define H3LIS100_INT1_THS           0x32
#define H3LIS100_INT1_DURATION      0x33
#define H3LIS100_INT2_CFG           0x34
#define H3LIS100_INT2_SRC           0x35
#define H3LIS100_INT2_THS           0x36
#define H3LIS100_INT2_DURATION      0x37

class Accel_H3LIS100 : public Sensor {
    private:

    public:
        Accel_H3LIS100(I2C_HandleTypeDef *i2cHandler, Data *data) : Sensor(i2cHandler, address, data) {}

        bool begin() override;
        void get_data() override;
};

#endif