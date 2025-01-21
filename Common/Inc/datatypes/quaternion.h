#ifndef QUATERNION_H
#define QUATERNION_H

/**
 * A Quaternion
 */
class Quaternion {
private:
    float x;
    float y;
    float z;
    float w;

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
    Quaternion(float x, float y, float z, float w); 

    float getX();
    float getY();
    float getZ();
    float getW();

    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setW(float w);   
};

#endif /* QUATERNION_H */
