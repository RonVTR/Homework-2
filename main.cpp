#include <iostream>
#include <ctime>
#include "player.h"
#include "wheel.h"


int main() {
    srand(static_cast<unsigned int>(time(0)));

    int maxWheelValue;
    std::cout << "Enter the number of values on the wheel (between 6 and 20): ";
    std::cin >> maxWheelValue;

    if (maxWheelValue < 6 || maxWheelValue > 20) {
        std::cerr << "Invalid input. Number of values on the wheel must be between 6 and 20." << std::endl;
        return 1;
    }
    
    //The player does not set a minimum value for the wheel. That direction states that the wheel must have at least 6 values starting at 1
    Player player(100, maxWheelValue);
    Wheel house(maxWheelValue);

    while (player.getMoney() > 0) {
        int bet, betChange;
        int houseResult1, houseResult2 = 0;
        std::cout << "Enter your bet: ";
        std::cin >> bet;

        if (bet > player.getMoney() || bet <= 0) {
            std::cerr << "Invalid bet amount. Please enter a valid bet." << std::endl;
            continue;
        }

        //Player sees what the roll to decide if they want to change their bet
        int playerResult = player.spinWheel();
        std::cout << "You Rolled: " << playerResult << std::endl;

        std::cout << "Enter your bet change (1 for double, 2 for halve, 3 for no change): ";
        std::cin >> betChange;

        while (betChange != 1 && betChange != 2 && betChange != 3) {
            std::cerr << "Invalid bet change. Please enter 1, 2, or 3." << std::endl;
            std::cin >> betChange;
        }
        if (betChange == 1 && player.getMoney() >= bet*2){
            bet = bet * 2;
        }
        else if (betChange == 1 && player.getMoney() < bet*2){
            std::cout << "You do not have enough money to double your bet..." << std::endl;
            std::cout << "Continuing without changing bet" << std::endl;
            betChange = 3;
        }
        else if (betChange == 2){
            bet = bet * .5;
        }


        if (betChange == 1 || betChange == 2){
            houseResult1 = house.spin();
            houseResult2 = house.spin();
            std::cout << "House results: " << houseResult1 << ", " << houseResult2 << std::endl;

        }
        else {
            houseResult1 = house.spin();
            std::cout << "House results: " << houseResult1 << std::endl;
        }


        


        //I dont think continue is a good choice for catching invalid inputs becuase then it rerolls everything



        if (playerResult > houseResult1 && playerResult > houseResult2) {
            std::cout << "Player wins!" << std::endl;
            player.changeMoney(bet);
        } else {
            std::cout << "House wins!" << std::endl;
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
