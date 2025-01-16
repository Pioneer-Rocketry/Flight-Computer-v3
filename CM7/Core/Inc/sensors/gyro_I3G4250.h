
#ifndef GYRO_I3G4250_H
#define GYRO_I3G4250_H

#include "sensors/sensors.hpp"

// Addresses
#define I3G4250_ADDRESS 0x68 // Address when SDO/AS0 is 0

// Who Am I ID
#define I3G4250_ID  0xD3

// Register addresses
#define I3G4250_WHO_AM_I        0x0F
#define I3G4250_CTRL_REG1       0x20
#define I3G4250_CTRL_REG2       0x21
#define I3G4250_CTRL_REG3       0x22
#define I3G4250_CTRL_REG4       0x23
#define I3G4250_CTRL_REG5       0x24
#define I3G4250_REFERENCE       0x25
#define I3G4250_OUT_TEMP        0x26
#define I3G4250_STATUS_REG      0x27
#define I3G4250_OUT_X_H         0x28
#define I3G4250_OUT_X_L         0x29
#define I3G4250_OUT_Y_H         0x2A
#define I3G4250_OUT_Y_L         0x2B
#define I3G4250_OUT_Z_H         0x2C
#define I3G4250_OUT_Z_L         0x2D
#define I3G4250_FIFO_CTRL_REG   0x2E
#define I3G4250_FIFO_SRC_REG    0x2F
#define I3G4250_INT1_CFG        0x30
#define I3G4250_INT1_SRC        0x31
#define I3G4250_INT1_THS_XH     0x32
#define I3G4250_INT1_THS_XL     0x33
#define I3G4250_INT1_THS_YH     0x34
#define I3G4250_INT1_THS_YL     0x35
#define I3G4250_INT1_THS_ZH     0x36
#define I3G4250_INT1_THS_ZL     0x37
#define I3G4250_INT1_DURATION   0x38

class Gyro_I3G4250 : public Sensor {
private:

public:
    Gyro_I3G4250(I2C_HandleTypeDef *i2cHandler, Data *data);

    bool begin() override;
    void get_data() override;
};

#endif