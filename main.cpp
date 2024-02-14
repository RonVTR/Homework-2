#include <iostream>
#include <ctime>
#include "player.h"
#include "wheel.h"


int main() {
    srand(static_cast<unsigned int>(time(0)));

    int minWheelValue, maxWheelValue;
    std::cout << "Enter the number of values on the wheel (between 6 and 20): ";
    std::cin >> minWheelValue >> maxWheelValue;

    if (minWheelValue < 6 || maxWheelValue > 20) {
        std::cerr << "Invalid input. Number of values on the wheel must be between 6 and 20." << std::endl;
        return 1;
    }

    Player player(100, minWheelValue, maxWheelValue);

    while (player.getMoney() > 0) {
        int bet, betChange;
        std::cout << "Enter your bet: ";
        std::cin >> bet;

        if (bet > player.getMoney() || bet <= 0) {
            std::cerr << "Invalid bet amount. Please enter a valid bet." << std::endl;
            continue;
        }

        std::cout << "Enter your bet change (1 for double, 2 for halve, 3 for no change): ";
        std::cin >> betChange;

        if (betChange != 1 && betChange != 2 && betChange != 3) {
            std::cerr << "Invalid bet change. Please enter 1, 2, or 3." << std::endl;
            continue;
        }

        int playerResult = player.spinWheel();
        int houseResult1 = player.spinWheel();
        int houseResult2 = player.spinWheel();

        std::cout << "Player result: " << playerResult << std::endl;
        std::cout << "House results: " << houseResult1 << ", " << houseResult2 << std::endl;

        if ((playerResult > houseResult1 && playerResult > houseResult2) ||
            (betChange == 1 && (playerResult > houseResult1 || playerResult > houseResult2)) ||
            (betChange == 2 && playerResult > houseResult1 && playerResult > houseResult2)) {
            std::cout << "Player wins!" << std::endl;
            if (betChange == 1)
                player.changeMoney(bet);
            else if (betChange == 2)
                player.changeMoney(-bet / 2);
            else
                player.changeMoney(bet);
        } else {
            std::cout << "House wins!" << std::endl;
            if (betChange == 1)
                player.changeMoney(-bet);
            else if (betChange == 2)
                player.changeMoney(-bet / 2);
            else
                player.changeMoney(-bet);
        }

        std::cout << "Player's money: " << player.getMoney() << std::endl;

        char playAgain;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y')
            break;
    }

    std::cout << "Game over!" << std::endl;

    return 0;
}
