#include "BNO055.hpp"
#include <Arduino.h>
#include <Wire.h>


BNO055(uint8_t address) {
    this->mode = OPMODE_CONFIG;
}


void BNO055::Begin() {
    Wire.begin();

    uint8_t id { read8(CHIP_ID_ADDR) };
    if(id != BNO055_CHIP_ID) {
        id = read8(CHIP_ID_ADDR);

        if(id != BNO055_CHIP_ID)
            throw String("Can't read the correct chip ID.");
    }

    write8(SYS_TRIGGER_ADDR, 0x20);
    while(read8(CHIP_ID_ADDR) != BNO055_CHIP_ID) delay(30);

    write8(PWR_MODE_ADDR, PWMODE_NORMAL);

    write8(PAGE_ID_ADDR, 0);
    write8(SYS_TRIGGER_ADDR, 0);
    delay(20);

    SetMode(OPMODE_NDOF);
}


void SetMode(OPMODE mode) {
    this->mode = mode;
    write8(OPR_MODE_ADDR, mode);
    delay(25);
}


float BNO055::GetTemperature() const {
    return static_cast<float>(read8(TEMP_ADDR));
}

Vector3<float> BNO055::GetEuleur() const {
    auto xyz = readVec(EULER_H_LSB_ADDR);
    xyz[0] /= 16.;
    xyz[1] /= 16.;
    xyz[2] /= 16.;

    return xyz;
}


uint8_t BNO055::read8(uint8_t reg_addr) {
    Wire.beginTransmission(this->addr);
    Wire.write(reg_addr);
    Wire.endTransmission(false);
    Wire.requestForm(this->addr, 1);

    return Wire.read();
}

uint8_t BNO055::readLen(uint8_t reg_addr, uint8_t* buf, size_t len) {
    Wire.beginTransmission(this->addr);
    Wire.write(reg_addr);
    Wire.endTransmission(false);
    Wire.requestForm(this->addr, len);

    for(size_t i {0}; i < len; i++)
        buf[i] = Wire.read();
}

Vector3<float> BNO055::readVec(uint8_t reg_addr) {
    Vector3<float> result;
    uint8_t buf[6];

    readLen(reg_addr, buf, 6);

    result[0] = static_cast<float>(static_cast<int16_t>(buf[0]) | ( static_cast<int16_t>(buf[1]) << 8));
    result[1] = static_cast<float>(static_cast<int16_t>(buf[2]) | ( static_cast<int16_t>(buf[3]) << 8));
    result[2] = static_cast<float>(static_cast<int16_t>(buf[4]) | ( static_cast<int16_t>(buf[5]) << 8));

    return result;
}

uint8_t BNO055::write8(uint8_t reg_addr, uint8_t value) {
    Wire.beginTransmission(this->addr);
    Wire.write(reg_addr);
    Wire.write(value);
    Wire.endTransmission();
}
