#include "sensors/baro_MS5607.h"

Baro_MS5607::Baro_MS5607(I2C_HandleTypeDef *i2cHandler, Data *data)
    : Sensor(i2cHandler, MS5607_ADDRESS, data) {
}

bool Baro_MS5607::begin() {

}

void Baro_MS5607::get_data() {

}