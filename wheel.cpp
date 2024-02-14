#include "wheel.h"
#include "player.h"



int Wheel::spin() {
    return minValue + rand() % (maxValue - minValue + 1);
}
