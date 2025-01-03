
#ifndef ACCEL_AIS3624_H
#define ACCEL_AIS3624_H

#include "sensors/sensors.hpp"

// Addresses
#define AIS3624_ADDRESS 0x19 // Address when SDO/AS0 is 1

// Who Am I ID
#define AIS3624_ID  0x32

// Register addresses
#define AIS3624_WHO_AM_I           0x0F
#define AIS3624_CTRL_REG1          0x20
#define AIS3624_CTRL_REG2          0x21
#define AIS3624_CTRL_REG3          0x22
#define AIS3624_CTRL_REG4          0x23
#define AIS3624_CTRL_REG5          0x24
#define AIS3624_HP_FILTER_RESET    0x25
#define AIS3624_REFERENCE          0x26
#define AIS3624_STATUS_REG         0x27
#define AIS3624_OUT_X              0x29
#define AIS3624_OUT_Y              0x2B
#define AIS3624_OUT_Z              0x2D
#define AIS3624_INT1_CFG           0x30
#define AIS3624_INT1_SRC           0x31
#define AIS3624_INT1_THS           0x32
#define AIS3624_INT1_DURATION      0x33
#define AIS3624_INT2_CFG           0x34
#define AIS3624_INT2_SRC           0x35
#define AIS3624_INT2_THS           0x36
#define AIS3624_INT2_DURATION      0x37

class Accel_AIS3624 : public Sensor {
    private:

    public:
        Accel_AIS3624(I2C_HandleTypeDef *i2cHandler, Data *data) : Sensor(i2cHandler, address, data) {}

        bool begin() override;
        void get_data() override;
};

#endif