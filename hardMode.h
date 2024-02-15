#include "wheel.h"

class HardMode : protected Wheel {
    private:
        //Variables to keep track of wins and loses
        int winsInRow = 0;
        int baseMax = 10;

    public:
        //Default constructor, uses default constructor for wheel as well
        HardMode() {baseMax = maxValue;}

        //Constructor to initialize wheel's max value
        HardMode(int Value) : Wheel(Value), baseMax(Value) {}

        void lose() {
            maxValue ++;
            winsInRow = 0;
        }

        void win() {
            winsInRow ++;
            if (winsInRow % 2 == 0 && maxValue > baseMax) {
                maxValue--;
            }
        }

        int spin(int playerVal, int changedBet) {

            int val1 = minValue + rand() % (maxValue - minValue + 1);
            int val2 = 0;

            if (changedBet == 2 || changedBet == 1){
                val2 = minValue + rand() % (maxValue - minValue + 1);
            }

            if(changedBet == 1 && playerVal < val1 || playerVal < val2){
                win();
            }
            else if (changedBet == 2 || changedBet == 3 && playerVal < val1 && playerVal < val2) {
                win();
            }
            else {lose();}
            return val1, val2;

        }


};