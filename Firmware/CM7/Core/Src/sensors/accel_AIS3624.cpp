#include "sensors/accel_AIS3624.h"

Accel_AIS3624::Accel_AIS3624(I2C_HandleTypeDef *i2cHandler, Data *data)
    : Sensor(i2cHandler, AIS3624_ADDRESS, data) {
}

bool Accel_AIS3624::begin() {

}

void Accel_AIS3624::get_data() {

}