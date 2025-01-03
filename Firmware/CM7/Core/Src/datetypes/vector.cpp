#include "datatypes/vector.h"

Vector::Vector() {
    this->zero();
}

Vector::Vector(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector::setX(double x) { this->x = x; }
void Vector::setY(double y) { this->y = y; }
void Vector::setZ(double z) { this->z = z; }

double Vector::getX() { return this->x; }
double Vector::getY() { return this->y; }
double Vector::getZ() { return this->z; }

void Vector::zero() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector Vector::operator+(Vector v) {
    return Vector(this->x + v.getX(), this->y + v.getY(), this->z + v.getZ());
}

Vector Vector::operator-(Vector v) {
    return Vector(this->x - v.getX(), this->y - v.getY(), this->z - v.getZ());
}

Vector Vector::operator*(double scalar) {
    return Vector(this->x * scalar, this->y * scalar, this->z * scalar);
}

Vector Vector::operator/(double scalar) {
    return Vector(this->x / scalar, this->y / scalar, this->z / scalar);
}

double Vector::dot(Vector v) {
    return this->x * v.getX() + this->y * v.getY() + this->z * v.getZ();
}

Vector Vector::normalize() {
    double length = this->magnitude();
    return Vector(this->x / length, this->y / length, this->z / length);
}

double Vector::magnitude() {
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}