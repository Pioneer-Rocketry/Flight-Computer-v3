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
    // 001 : Normal Power Mode
    // 01 : 100 Hz
    // 111 : XYZ Axis Enable
    uint8_t ctrlReg1 = 0b00101111;
    write_I2C(AIS3624_CTRL_REG1, &ctrlReg1);

    // CTRL_REG2
    // 0 : Normal mode
    // 00: No filter
    // 0 : Filter bypass
    // 0000 : Pertain to high pass filter
    uint8_t ctrlReg2 = 0b00000000;
    write_I2C(AIS3624_CTRL_REG2, &ctrlReg2);

    // CTRL_REG3
    // 0 : Interrupt active high
    // 0 : Push / pull
    // 0 : INT 2 Not latched
    // 10 : INT 2 Data ready
    // 0 : INT 1 Not latched
    // 10 : INT 1 Data ready
    uint8_t ctrlReg3 = 0b00000000;
    write_I2C(AIS3624_CTRL_REG3, &ctrlReg3);

    // CTRL_REG4
    // 0 : Continuous update
    // 0 : Least significant bit
    // 01 : Range selection (-12g, +12g)
    // 0 : Self-test plus
    // 0 : Self-test disabled
    // 0 : 4-wire SPI interface
    uint8_t ctrlReg4 = 0b00010000;
    write_I2C(AIS3624_CTRL_REG4, &ctrlReg4);

    // CTRL_REG5
    // 000000 : Zeroed out
    // 00 : Sleep-to-wake disabled
    uint8_t ctrlReg5 = 0b00000000;
    write_I2C(AIS3624_CTRL_REG5, &ctrlReg5);
}

void Accel_AIS3624::get_data() {

    uint8_t data[3];

    read_I2C(AIS3624_OUT_X, &data[0]);
    read_I2C(AIS3624_OUT_Y, &data[1]);
    read_I2C(AIS3624_OUT_Z, &data[2]);

    // TODO: Two's compliment

    this->data->AIS2624_Accel.setX(data[0]);
    this->data->AIS2624_Accel.setY(data[1]);
    this->data->AIS2624_Accel.setZ(data[2]);
}