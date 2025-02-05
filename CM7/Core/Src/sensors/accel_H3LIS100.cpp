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
    uint8_t ctrlReg1 = 0b00101000;
    write_I2C(H3LIS100_CTRL_REG1, &ctrlReg1);

    // CTRL_REG2
    // 0 : Normal Mode
    // 00 : Normal Mode / No Filter
    // 000 : Dont Care cause were not using the filter
    uint8_t ctrlReg2 = 0b00000000;
    write_I2C(H3LIS100_CTRL_REG2, &ctrlReg2);

    // CTRL_REG3
    // 0 : Active High
    // 0 : Open Drain
    // 0 : Default
    // 10 : Data Ready Interrupt
    uint8_t ctrlReg3 = 0b00010000;
    write_I2C(H3LIS100_CTRL_REG3, &ctrlReg3);

}

void Accel_H3LIS100::get_data() {

    uint8_t data[3];

    read_I2C(H3LIS100_OUT_X, &data[0]);
    read_I2C(H3LIS100_OUT_Y, &data[1]);
    read_I2C(H3LIS100_OUT_Z, &data[2]);

    // TODO: Convert to 2 complement

    this->data->H2LIS100_Accel.setX(data[0]);
    this->data->H2LIS100_Accel.setY(data[1]);
    this->data->H2LIS100_Accel.setZ(data[2]);

}