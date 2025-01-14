
#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

/**
 * A 3D vector
 */
class Vector {
    private:
        double x;
        double y;
        double z;

    public:
        Vector();

        /**
         * Construct a new Vector object
         *
         * @param x The x component of the vector
         * @param y The y component of the vector
         * @param z The z component of the vector
         */
        Vector(double x, double y, double z);

        double getX();
        double getY();
        double getZ();

        void setX(double x);
        void setY(double y);
        void setZ(double z);

        void zero();

        Vector operator+(Vector v);
        Vector operator-(Vector v);
        Vector operator*(double scalar);
        Vector operator/(double scalar);

        double dot(Vector v);
        Vector normalize();
        double magnitude();
};

#endif