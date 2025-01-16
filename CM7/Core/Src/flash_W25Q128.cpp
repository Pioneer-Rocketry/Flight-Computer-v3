#include "flash_W25Q128.h"

Flash_W25Q128::Flash_W25Q128(QSPI_HandleTypeDef *qspi,Data *data) {
    this->qspi = qspi;
    this->data = data;
}

bool Flash_W25Q128::begin() {
    return true;
}

void Flash_W25Q128::write_data() {

}

void Flash_W25Q128::read() {

}

void Flash_W25Q128::write() {

}