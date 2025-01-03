#include "sensors/gyro_I3G4250.h"

Gyro_I3G4250::Gyro_I3G4250(I2C_HandleTypeDef *i2cHandler, Data *data)
    : Sensor(i2cHandler, I3G4250_ADDRESS, data) {
}

bool Gyro_I3G4250::begin() {

}

void Gyro_I3G4250::get_data() {

}