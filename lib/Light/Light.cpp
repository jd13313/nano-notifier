#include <Light.h>

void Light::setColor(int r, int g, int b) {
    analogWrite(PIN_R, r);
    analogWrite(PIN_G, g);
    analogWrite(PIN_B, b);
}

void Light::setPins(int r, int g, int b) {
    PIN_R = r;
    PIN_G = g;
    PIN_B = b;
}