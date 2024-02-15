#include "wheel.h"


class Player {
private:
    int money;
    Wheel wheel;

public:
    Player(int initialMoney, int maxVal) : money(initialMoney), wheel(maxVal) {}

    int getMoney() const {
        return money;
    }

    void changeMoney(int amount) {
        money += amount;
    }

    int spinWheel();
};

