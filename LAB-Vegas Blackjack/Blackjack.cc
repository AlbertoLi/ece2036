#include "Blackjack.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
#include <unistd.h>

/**
 * Queries player for action: (h)it or (s)tand
 * @return Hit_or_stand Enum determins action player wants to take
 */
Hit_or_Stand Blackjack::queryPlayer() {
    std::string action;
    do {
        std::cout << "What would you like to do? Enter (h)it or (s)tand: ";
        std::cin >> action;
        if (!action.empty()) {
            std::transform(action.begin(),action.end(),action.begin(), ::tolower); //turns action to lowercase
            /** Poll for Hit */
            if (action.substr(0,1) == "h") {
                return HIT;
            }
            /** Poll for Stand */
            if (action.substr(0,1) == "s") {
                return Hit_or_Stand(STAND);
            }
        }
    } while (!(action.substr(0,1) == "h" || action.substr(0,1) == "s"));
}

/**
 * Queries player for doubledown if eligible; (y)es or (n)o
 * @return boolean determines whether player wants to double down or not
 */
bool Blackjack::queryDoubledown() {
    std::string action;
    do {
        std::cout << "Would you like to double down? Enter (y)es or (n)o: ";
        std::cin >> action;
        if (!action.empty()) {
            std::transform(action.begin(),action.end(),action.begin(), ::tolower); //turns action to lowercase
            /** Poll for yes */
            if (action.substr(0,1) == "y") {
                return true;
            }
            /** Poll for no */
            if (action.substr(0,1) == "n") {
                return false;
            }
        }
    } while (!(action.substr(0,1) == "y" || action.substr(0,1) == "n"));
}

/**
 * Main code stump for determining rules of Blackjack.
 * Evaluates (1) Player actions, (2) Dealer actions, (3) Winner
 * @param  money [description]
 * @return       [description]
 */
double Blackjack::play(double money) {
    bool doubledown = 0;
    Hit_or_Stand action;
    playerBet = money;
    action = HIT; //initialize to hit so while loop will query
    dealerHand.printFirstCard();
    playerHand.printHand();

    /** doubledown conditions: Blackjack (2 cards = 21) AND 2*bet <= playerMoney */
    if (!(playerHand.getNumber_of_cards() == 2 && playerHand.getValue() == 21)
        && playerBet*2 <= playerMoney) {
        doubledown = queryDoubledown();
    if (doubledown) {
        playerBet = playerBet*2;
        std::cout << "Doubledown! Bet has been increased from "
        << money << " to " << playerBet << " dollars" << std::endl;
    };
}

    /** Player POV */
if (doubledown) {
    ++playerHand;
    playerHand.printHand();
    usleep(2000000);
} else {
    while ((action == HIT) && playerHand.getValue() < 21) {
        action = queryPlayer();
        if (action == HIT) {
            ++playerHand;
            playerHand.printHand();
        }
    }
}

    /** Dealer POV */
dealerHand.printHand();
usleep(2000000);
while (dealerHand.getValue() < 17) {
    if (dealerHand.getValue() < 17) {
        ++dealerHand;
        dealerHand.printHand();
        usleep(2000000);

    }
}

    /** Evaluate Winner */
    if (playerHand.getValue() > 21) { //Player busts
        money = playerMoney - playerBet;
        std::cout << "Player's hand is bust" << std::endl;
        std::cout << "Player has " << money << " dollars" << std::endl;
    } else if (dealerHand.getValue() > 21) { //Dealer busts
        if (playerHand.getNumber_of_cards() == 2 && playerHand.getValue() == 21) { //Blackjack checking
            money = playerMoney + playerBet*1.5;
            std::cout << "Dealer's hand is bust. Player Wins with Blackjack!" <<std::endl;
            std::cout << "Player has " << money << " dollars" << std::endl;
        } else {
            money = playerMoney + playerBet;
            std::cout << "Dealer's hand is bust. Player Wins!" <<std::endl;
            std::cout << "Player has " << money << " dollars" << std::endl;
        }
    } else if (playerHand < dealerHand) { //Player loses
        money = playerMoney - playerBet;
        std::cout << "Dealer wins." <<std::endl;
        std::cout << "Player has " << money << " dollars" << std::endl;
    } else if (playerHand > dealerHand) { //Player wins
        if (playerHand.getNumber_of_cards() == 2 && playerHand.getValue() == 21) {
            money = playerMoney + playerBet*1.5;
            std::cout << "Player Wins with Blackjack!" <<std::endl;
            std::cout << "Player has " << money << " dollars" << std::endl;
        } else {
            money = playerMoney + playerBet;
            std::cout << "Player Wins!" <<std::endl;
            std::cout << "Player has " << money << " dollars" << std::endl;
        }
    }
    else { //Tie (player.getValue() == dealer.getValue())
        money = playerMoney;
        std::cout << "Player and Dealer Push. Tie!" << std::endl;
        std::cout << "Player has " << money << " dollars" << std::endl;
    }
    return money;
}