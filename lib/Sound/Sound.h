#ifndef Sound_h
#define Sound_h
#include <Arduino.h>
#include <Note.h>

class Sound {
    public: 
        void setBeeperDataPin(int);
        void beep(int, int);
        void melody(Note*, int);
    protected:
        int PIN_BEEPER_DATA;
};

#endif