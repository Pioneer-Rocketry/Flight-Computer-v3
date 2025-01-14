#include "datatypes/quaternion.h"

Quaternion::Quaternion() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 1;
}

Quaternion::Quaternion(double x, double y, double z, double w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

double Quaternion::getX() { return this->x; }
double Quaternion::getY() { return this->y; }
double Quaternion::getZ() { return this->z; }
double Quaternion::getW() { return this->w; }

void Quaternion::setX(double x) { this->x = x; }
void Quaternion::setY(double y) { this->y = y; }
void Quaternion::setZ(double z) { this->z = z; }
void Quaternion::setW(double w) { this->w = w; }