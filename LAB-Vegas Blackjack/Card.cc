#include "Card.h"
#include <string>
#include <stdlib.h>

/**
 * Public Card constructor
 * @param initial_value set to random card value 1-11
 * @param typeString set to 1 of 13 cards in deck
 */
Card::Card() {

    initial_value = 1 + rand() % 13;

  /** typeString */
    switch (initial_value) {
        case 1:
        typeString = "Ace";
        break;
        case 2:
        typeString = "Two";
        break;
        case 3:
        typeString = "Three";
        break;
        case 4:
        typeString = "Four";
        break;
        case 5:
        typeString = "Five";
        break;
        case 6:
        typeString = "Six";
        break;
        case 7:
        typeString = "Seven";
        break;
        case 8:
        typeString = "Eight";
        break;
        case 9:
        typeString = "Nine";
        break;
        case 10:
        typeString = "Ten";
        break;
        case 11:
        typeString = "Jack";
        initial_value = 10;
        break;
        case 12:
        typeString = "Queen";
        initial_value = 10;
        break;
        case 13:
        typeString = "King";
        initial_value = 10;
        default:
        break;
    }
  /** Redefine initial Ace Value to 11 */
    if (initial_value == 1) {initial_value = 11;}
}


/** Public Getter member functions */
std::string Card::getType() const {return typeString;}
int Card::getValue() const {return initial_value;}
