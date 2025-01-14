#ifndef QUATERNION_H
#define QUATERNION_H

/**
 * A Quaternion
 */
class Quaternion {
    private:
        double x;
        double y;
        double z;
        double w;

    public:
        Quaternion();

        /**
         * Construct a new Quaternion object
         *
         * @param x The x component of the quaternion
         * @param y The y component of the quaternion
         * @param z The z component of the quaternion
         * @param w The w component of the quaternion
         */
        Quaternion(double x, double y, double z, double w); 

        double getX();
        double getY();
        double getZ();
        double getW();

        void setX(double x);
        void setY(double y);
        void setZ(double z);
        void setW(double w);   
};

#endif /* QUATERNION_H */
