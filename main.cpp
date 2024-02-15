#include <iostream>
#include <ctime>
#include "player.h"
#include "wheel.h"


int main() {
    srand(static_cast<unsigned int>(time(0)));

    // Prompts the user to enter the maximum values on the wheel
    int maxWheelValue;
    std::cout << "Enter the number of values on the wheel (between 6 and 20): ";
    std::cin >> maxWheelValue;

    //Loops until a number between 6 and 20 is inputted
    while (maxWheelValue < 6 || maxWheelValue > 20) {
        std::cerr << "Invalid input. Number of values on the wheel must be between 6 and 20." << std::endl;
        std::cin >> maxWheelValue;
    }

    //Creates the house and player objects, player starts with $100
    Player player(100, maxWheelValue);
    Wheel house(maxWheelValue);

    //Checks to see if the player has ran out of money before playing again
    while (player.getMoney() > 0) {
        int bet, betChange;
        int houseResult1, houseResult2 = 0;

        //Player inputs the amount they want to bet and program ensures that it is
        //a positive value and within the amount they have
        std::cout << "Enter your bet: ";
        std::cin >> bet;
        if (bet > player.getMoney() || bet <= 0) {
            std::cerr << "Invalid bet amount. Please enter a valid bet." << std::endl;
            continue;
        }

        std::cout << std::endl;

        //Player sees what the roll to decide if they want to change their bet
        int playerResult = player.spin();
        std::cout << "You Rolled: " << playerResult << std::endl;

        std::cout << "Enter your bet change (1 for double, 2 for halve, 3 for no change): ";
        std::cin >> betChange;

        while (betChange != 1 && betChange != 2 && betChange != 3) {
            std::cerr << "Invalid bet change. Please enter 1, 2, or 3." << std::endl;
            std::cin >> betChange;
        }

        //Doubles the bet if they can afford it
        if (betChange == 1 && player.getMoney() >= bet*2){
            bet = bet * 2;
        }
        //If they chose to double and can't afford it the program continues without changing the bet
        else if (betChange == 1 && player.getMoney() < bet*2){
            std::cout << "You do not have enough money to double your bet..." << std::endl;
            std::cout << "Continuing without changing bet" << std::endl;
            betChange = 3;
        }
        //"Gives" half the bet to the house 
        else if (betChange == 2){
            bet = bet * .5;
            player.changeMoney(-bet);
        }

        std::cout << std::endl;

        //Rolls twice f the player changed their bet
        if (betChange == 1 || betChange == 2){
            houseResult1 = house.spin();
            houseResult2 = house.spin();
            std::cout << "House results: " << houseResult1 << ", " << houseResult2 << std::endl;

        }
        else {
            houseResult1 = house.spin();
            std::cout << "House result: " << houseResult1 << std::endl;
        }


        //Player wins if their bet beats both the house's rolls
        //The second roll is initialized to 0 so if the house did not roll twice the player 
        //automatically beats the second roll
        if (playerResult > houseResult1 && playerResult > houseResult2) {
            std::cout << "Player wins!" << std::endl;
            player.changeMoney(bet);
        } 
        //If the player halved their bet and their roll is higher than either of the house's they win
        else if (betChange == 2 && (playerResult > houseResult1 || playerResult > houseResult2)){
            std::cout << "Player wins!" << std::endl;
            player.changeMoney(bet);
        }
        //House wins
        else {
            std::cout << "House wins!" << std::endl;
            player.changeMoney(-bet);
        }

        //Tells the player how much money they have left and asks if they want to play again
        std::cout << std::endl;
        std::cout << "Player's money: " << player.getMoney() << std::endl;

        char playAgain;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y')
            break;
    }

    if (player.getMoney() <= 0) {
        std::cout << std::endl << "You ran out of money :(" << std::endl;
    }
    std::cout << "Game over!" << std::endl;

    return 0;
}
