#include <cstdlib>
#include <ctime>
#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
private:
    int minValue = 1;
    int maxValue;

public:
    Wheel(int maxVal = 10) : maxValue(maxVal) {}

    int spin(); 
};

#endif // WHEEL_H