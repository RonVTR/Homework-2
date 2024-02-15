#include "wheel.h"


class Player : public Wheel{
private:
    int money;

public:
    //Constructor that sets players money and the values on the wheel
    Player(int initialMoney, int maxVal) : money(initialMoney), Wheel(maxVal) {}

    int getMoney() const {
        return money;
    }

    //Function that can be called to add or subtract a bet from the player's money
    void changeMoney(int amount) {
        money += amount;
    }

};

