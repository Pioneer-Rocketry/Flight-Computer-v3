
#ifndef BARO_MS5607_H
#define BARO_MS5607_H

#include "sensors/sensors.hpp"

// Addresses
#define MS5607_ADDRESS 0x68

// Who Am I ID
#define MS5607_ID 0xD3

// Commands
#define MS5607_RESET 0x1E
#define MS5607_PROM_READ 0xA6

class Baro_MS5607 : public Sensor {
private:

public:
    Baro_MS5607(I2C_HandleTypeDef *i2cHandler, Data *data);

    bool begin() override;
    void get_data() override;
};

#endif