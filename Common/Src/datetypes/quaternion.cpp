#include "datatypes/quaternion.h"

Quaternion::Quaternion() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 1;
}

Quaternion::Quaternion(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

float Quaternion::getX() { return this->x; }
float Quaternion::getY() { return this->y; }
float Quaternion::getZ() { return this->z; }
float Quaternion::getW() { return this->w; }

void Quaternion::setX(float x) { this->x = x; }
void Quaternion::setY(float y) { this->y = y; }
void Quaternion::setZ(float z) { this->z = z; }
void Quaternion::setW(float w) { this->w = w; }

void Quaternion::normalize() {
    float length = sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
    this->x /= length;
    this->y /= length;
    this->z /= length;
    this->w /= length;
}