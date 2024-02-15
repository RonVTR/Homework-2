#include <cstdlib>
#include <ctime>
#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
protected:
    int minValue;
    int maxValue;

public:
    //Default constructor that sets the min value to 1 and the max value to 10
    Wheel() : maxValue(10), minValue(1) {}

    //Constructor that sets the max value on the wheel, and the min value to 1
    Wheel(int maxVal) : maxValue(maxVal), minValue(1) {}

    int spin(); 
};

#endif // WHEEL_H