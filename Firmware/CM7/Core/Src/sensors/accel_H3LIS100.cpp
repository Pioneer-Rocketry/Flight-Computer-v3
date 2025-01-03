#include "sensors/accel_H3LIS100.h"

Accel_H3LIS100::Accel_H3LIS100(I2C_HandleTypeDef *i2cHandler, Data *data)
    : Sensor(i2cHandler, H3LIS100_ADDRESS, data) {
}

void Accel_H3LIS100::begin() {

}

void Accel_H3LIS100::get_data() {

}