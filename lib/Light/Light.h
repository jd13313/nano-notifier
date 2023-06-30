#ifndef Light_h
#define Light_h

#include <Arduino.h>

class Light {
    public:
        void setPins(int, int, int);
        void setColor(int, int, int);
    protected:
        int PIN_R;
        int PIN_G;
        int PIN_B;
};

#endif