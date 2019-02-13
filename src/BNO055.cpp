#include "BNO055.hpp"
#include <Arduino.h>
#include <Wire.h>


BNO055::BNO055(uint8_t address) {
    this->addr = address;
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

    SetMode(OPMODE_CONFIG);

    // Reset
    write8(SYS_TRIGGER_ADDR, 0x20);
    while(read8(CHIP_ID_ADDR) != BNO055_CHIP_ID) delay(10);
    delay(50);

    // Set normal powermode
    write8(PWR_MODE_ADDR, PWMODE_NORMAL);
    delay(10);

    write8(PAGE_ID_ADDR, 0);
    write8(SYS_TRIGGER_ADDR, 0);
    delay(10);

    SetMode(OPMODE_NDOF);
}


void BNO055::SetMode(OPMODE mode) {
    this->mode = mode;
    write8(OPR_MODE_ADDR, mode);
    delay(25);
}

BNO055::OPMODE BNO055::GetMode() const {
    return this->mode;
}


void BNO055::SetUnits(uint8_t unitsel) {    
    write8(UNIT_SEL_ADDR, unitsel);
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


uint8_t BNO055::read8(uint8_t reg_addr) const {
    Wire.beginTransmission(this->addr);
    Wire.write(reg_addr);
    Wire.endTransmission(false);
    Wire.requestFrom(this->addr, static_cast<uint8_t>(1));

    return Wire.read();
}

void BNO055::readLen(uint8_t reg_addr, uint8_t* buf, size_t len) const {
    Wire.beginTransmission(this->addr);
    Wire.write(reg_addr);
    Wire.endTransmission(false);
    Wire.requestFrom(this->addr, len);

    for(size_t i {0}; i < len; i++)
        buf[i] = Wire.read();    
}

Vector3<float> BNO055::readVec(uint8_t reg_addr) const {
    Vector3<float> result(0, 0, 0);
    int16_t x, y, z;
    uint8_t buf[6];

    readLen(reg_addr, buf, 6);

    x = static_cast<int16_t>(buf[0]) | (static_cast<int16_t>(buf[1]) << 8);
    y = static_cast<int16_t>(buf[2]) | (static_cast<int16_t>(buf[3]) << 8);
    z = static_cast<int16_t>(buf[4]) | (static_cast<int16_t>(buf[5]) << 8);

    result[0] = static_cast<float>(x);
    result[1] = static_cast<float>(y);
    result[2] = static_cast<float>(z);

    return result;
}

void BNO055::write8(uint8_t reg_addr, uint8_t value) {
    Wire.beginTransmission(this->addr);
    Wire.write(reg_addr);
    Wire.write(value);
    Wire.endTransmission();
}
