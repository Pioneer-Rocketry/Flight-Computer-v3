#ifndef BARO_MS5607_H
#define BARO_MS5607_H

#include "sensors/sensors.hpp"

// Addresses
#define MS5607_ADDRESS 0x68

// Who Am I ID
#define MS5607_ID 0xD3

// Commands
#define MS5607_RESET 0x1E
#define MS5607_PROM_READ 0xA0 // 0xA0-0xAE, bits 4-6 are the address
#define MS5607_D1_CONVERSION 0x40 // 0x40-0x4E, bits 4-6 are for the OSR
#define MS5607_D2_CONVERSION 0x50 // 0x50-0x58, bits 4-6 are for the OSR
#define MS5607_READ_ADC 0x00

class Baro_MS5607 : public Sensor {
private:
    uint8_t OSR; // Oversampling Rate / How many samples are averaged

public:
    Baro_MS5607(I2C_HandleTypeDef *i2cHandler, Data *data);

    bool begin() override;
    void get_data() override;
};

#endif