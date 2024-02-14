#include <cstdlib>
#include <ctime>
#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
private:
    int minValue;
    int maxValue;

public:
    Wheel(int minVal = 1, int maxVal = 10) : minValue(minVal), maxValue(maxVal) {}

    int spin(); 
};

#endif // WHEEL_H