#include "sensors/accel_H3LIS100.h"

Accel_H3LIS100::Accel_H3LIS100(I2C_HandleTypeDef *i2cHandler, Data *data)
    : Sensor(i2cHandler, H3LIS100_ADDRESS, data) {
}

bool Accel_H3LIS100::begin() {
    uint8_t whoAmI;

    read_I2C(H3LIS100_WHO_AM_I, &whoAmI);
    if (whoAmI != H3LIS100_ID) {
        return false;
    }

    // Configuration

    // CTRL_REG1
    // 001 : Normal mode
    // 01 : 100 Hz
    // 1 : Enable Z Axis
    // 1 : Enable Y Axis
    // 1 : Enable X Axis
    uint8_t ctrlReg1 = 0b00101111;
    write_I2C(H3LIS100_CTRL_REG1, &ctrlReg1);

    // CTRL_REG2
    // 0 : Normal Mode
    // 00 : Normal Mode / No Filter
    // 00000 : Dont Care cause were not using the filter
    uint8_t ctrlReg2 = 0b00000000;
    write_I2C(H3LIS100_CTRL_REG2, &ctrlReg2);

    // CTRL_REG3
    // 0 : Active High
    // 0 : Open Drain
    // 0 : Default Value
    // 10 : Data Ready Interrupt
    // 0 : Default Value
    // 00 : 
    uint8_t ctrlReg3 = 0b00010000;
    write_I2C(H3LIS100_CTRL_REG3, &ctrlReg3);

    // Skipped CTRL_REG4 b/c its related to SPI

    // Skipped CTRL_REG5 b/c its related to sleep and we dont sleep

    // INT1_CFG
    // 0 : Or Inter events
    // 0 : Skip Bit
    // 0 : Disable Z high events
    // 0 : Disable Z low events
    // 0 : Disable Y high events
    // 0 : Disable Y low events
    // 0 : Disable X high events
    // 0 : Disable X low events
    uint8_t int1Cfg = 0b00000000;
    write_I2C(H3LIS100_INT1_CFG, &int1Cfg);

    // INT1_THS
    // 0 : Skip Bit
    // 000 0000 : Default Threshold
    uint8_t int1Ths = 0b00000000;
    write_I2C(H3LIS100_INT1_THS, &int1Ths);

    // INT1_DURATION
    // 0 : Skip Bit
    // 000 0000 : Default Duration
    uint8_t int1Duration = 0b00000000;
    write_I2C(H3LIS100_INT1_DURATION, &int1Duration);

    // INT2_CFG
    // 0 : Or Inter events
    // 0 : Skip Bit
    // 0 : Disable Z high events
    // 0 : Disable Z low events
    // 0 : Disable Y high events
    // 0 : Disable Y low events
    // 0 : Disable X high events
    // 0 : Disable X low events
    uint8_t int2Cfg = 0b00000000;
    write_I2C(H3LIS100_INT2_CFG, &int2Cfg);

    // INT12THS
    // 0 : Skip Bit
    // 000 0000 : Default Threshold
    uint8_t int2Ths = 0b00000000;
    write_I2C(H3LIS100_INT2_THS, &int2Ths);

    // INT2_DURATION
    // 0 : Skip Bit
    // 000 0000 : Default Duration
    uint8_t int2Duration = 0b00000000;
    write_I2C(H3LIS100_INT2_DURATION, &int2Duration);
}

void Accel_H3LIS100::get_data() {
    uint8_t data[3];

    read_I2C(H3LIS100_OUT_X, &data[0]);
    read_I2C(H3LIS100_OUT_Y, &data[1]);
    read_I2C(H3LIS100_OUT_Z, &data[2]);

    // Sensor Reading * Sensitivity to get m/s^2
    this->data->H3LIS100_Accel.setX((float)((int8_t) data[0]) * H3LIS100_SENSITIVITY);
    this->data->H3LIS100_Accel.setY((float)((int8_t) data[1]) * H3LIS100_SENSITIVITY);
    this->data->H3LIS100_Accel.setZ((float)((int8_t) data[2]) * H3LIS100_SENSITIVITY);
}