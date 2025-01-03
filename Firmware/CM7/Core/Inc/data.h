
#ifndef DATA_H
#define DATA_H

#include "datatypes/vector.h"

class Data {
    public:
        void save();
        void log();

        Vector H2LIS100_Accel;
};

#endif