#include "sensors/accel_AIS3624.h"

Accel_AIS3624::Accel_AIS3624(I2C_HandleTypeDef *i2cHandler, Data *data)
    : Sensor(i2cHandler, AIS3624_ADDRESS, data) {
}

bool Accel_AIS3624::begin() {
    uint8_t whoAmI;

    read_I2C(AIS3624_WHO_AM_I, &whoAmI);
    if (whoAmI != AIS3624_ID) {
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
    write_I2C(AIS3624_CTRL_REG1, &ctrlReg1);

    // CTRL_REG2
    uint8_t ctrlReg2 = 0;
    ctrlReg2 |=     0b0 << 7; // Normal Mode
    ctrlReg2 |=    0b00 << 5; // Normal Mode / No Filter
    ctrlReg2 |= 0b00000 << 0; // Dont Care cause were not using the filter
    write_I2C(AIS3624_CTRL_REG2, &ctrlReg2);

    // CTRL_REG3
    uint8_t ctrlReg3 = 0b00000000;
    ctrlReg3 |=  0b0 << 7; // Interrupt active high
    ctrlReg3 |=  0b0 << 6; // Push / Pull
    ctrlReg3 |=  0b0 << 5; // INT 2 Not latched
    ctrlReg3 |= 0b10 << 3; // INT 2 Data ready
    ctrlReg3 |=  0b0 << 2; // INT 1 Not latched
    ctrlReg3 |= 0b10 << 0; // INT 1 Data ready
    write_I2C(AIS3624_CTRL_REG3, &ctrlReg3);

    // CTRL_REG4
    uint8_t ctrlReg4 = 0b00010000;
    ctrlReg4 |=  0b0 << 7; // Continuous update
    ctrlReg4 |=  0b0 << 6; // Little Endian
    ctrlReg4 |= 0b11 << 4; // Range selection (-24g, +24g)
    ctrlReg4 |=  0b0 << 3; // Self-test plus
    ctrlReg4 |=  0b0 << 2; // Self-test disabled
    ctrlReg4 |=  0b0 << 1; // 4-wire SPI interface
    write_I2C(AIS3624_CTRL_REG4, &ctrlReg4);

    // CTRL_REG5
    uint8_t ctrlReg5 = 0b00000000;
    ctrlReg5 |= 0b00 << 0; // Sleep-to-wake disabled
    write_I2C(AIS3624_CTRL_REG5, &ctrlReg5);
}

void Accel_AIS3624::get_data() {
    uint8_t data[6];

    read_I2C(AIS3624_OUT_X, &data[0], 2);
    read_I2C(AIS3624_OUT_Y, &data[2], 2);
    read_I2C(AIS3624_OUT_Z, &data[4], 2);

    this->data->AIS2624_Accel.setX(((float) (int16_t) (data[0] | data[1] << 8)) * AIS3624_SENSITIVITY);
    this->data->AIS2624_Accel.setY(((float) (int16_t) (data[2] | data[3] << 8)) * AIS3624_SENSITIVITY);
    this->data->AIS2624_Accel.setZ(((float) (int16_t) (data[4] | data[5] << 8)) * AIS3624_SENSITIVITY);
}