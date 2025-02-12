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
    uint8_t ctrlReg1 = 0;
    ctrlReg1 |= 0b001 << 5; // Normal mode
    ctrlReg1 |=  0b01 << 3; // 100 Hz
    ctrlReg1 |=   0b1 << 2; // Enable Z Axis
    ctrlReg1 |=   0b1 << 1; // Enable Y Axis
    ctrlReg1 |=   0b1 << 0; // Enable X Axis
    write_I2C(H3LIS100_CTRL_REG1, &ctrlReg1);

    // CTRL_REG2
    uint8_t ctrlReg2 = 0b00000000;
    ctrlReg2 |=     0b0 << 7; // Normal Mode
    ctrlReg2 |=    0b00 << 5; // Normal Mode / No Filter
    ctrlReg2 |= 0b00000 << 0; // Dont Care cause were not using the filter
    write_I2C(H3LIS100_CTRL_REG2, &ctrlReg2);

    // CTRL_REG3
    uint8_t ctrlReg3 = 0;
    ctrlReg3 |=   0b0 << 6; // Active High
    ctrlReg3 |=   0b0 << 5; // Open Drain
    ctrlReg3 |=   0b0 << 4; // Default Value
    ctrlReg3 |=  0b10 << 2; // Data Ready Interrupt
    ctrlReg3 |=   0b0 << 1; // Default Value
    ctrlReg3 |=   0b0 << 0; // Filter settings that arent used
    write_I2C(H3LIS100_CTRL_REG3, &ctrlReg3);

    // Skipped CTRL_REG4 b/c its related to SPI

    // Skipped CTRL_REG5 b/c its related to sleep and we dont sleep

    // INT1_CFG
    uint8_t int1Cfg = 0;
    int1Cfg |=  0b0 << 7; // Or Inter events
    int1Cfg |=  0b0 << 6; // Skip Bit
    int1Cfg |=  0b0 << 5; // Disable Z high events
    int1Cfg |=  0b0 << 4; // Disable Z low events
    int1Cfg |=  0b0 << 3; // Disable Y high events
    int1Cfg |=  0b0 << 2; // Disable Y low events
    int1Cfg |=  0b0 << 1; // Disable X high events
    int1Cfg |=  0b0 << 0; // Disable X low events
    write_I2C(H3LIS100_INT1_CFG, &int1Cfg);

    // INT1_THS
    uint8_t int1Ths = 0;
    int1Ths |=        0b0 << 7; // Skip Bit
    int1Ths |=  0b0000000 << 0; // Default Threshold
    write_I2C(H3LIS100_INT1_THS, &int1Ths);

    // INT1_DURATION
    uint8_t int1Duration = 0;
    int1Duration |=        0b0 << 7; // Skip Bit
    int1Duration |=  0b0000000 << 0; // Default Duration
    write_I2C(H3LIS100_INT1_DURATION, &int1Duration);

    // INT2_CFG
    uint8_t int2Cfg = 0;
    int2Cfg |=  0b0 << 7; // Or Inter events
    int2Cfg |=  0b0 << 6; // Skip Bit
    int2Cfg |=  0b0 << 5; // Disable Z high events
    int2Cfg |=  0b0 << 4; // Disable Z low events
    int2Cfg |=  0b0 << 3; // Disable Y high events
    int2Cfg |=  0b0 << 2; // Disable Y low events
    int2Cfg |=  0b0 << 1; // Disable X high events
    int2Cfg |=  0b0 << 0; // Disable X low events
    write_I2C(H3LIS100_INT2_CFG, &int2Cfg);

    // INT12THS
    uint8_t int2Ths = 0;
    int2Ths |=        0b0 << 7; // Skip Bit
    int2Ths |=  0b0000000 << 0; // Default Threshold
    write_I2C(H3LIS100_INT2_THS, &int2Ths);

    // INT2_DURATION
    uint8_t int2Duration = 0;
    int2Duration |=        0b0 << 7; // Skip Bit
    int2Duration |=  0b0000000 << 0; // Default Duration
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