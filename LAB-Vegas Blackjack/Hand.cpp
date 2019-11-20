#include "Hand.h"
#include <string>
#include <iostream>

/**
 * Public Constructor
 * @param hand_holder set to Player or Dealer
 * @number_of_cards set to 2 by ++ operator
 * @number_of_aces set to number of aces
 */
Hand::Hand(std::string person) {
    hand_holder = person;
    number_of_aces = 0;
    number_of_cards = 0;
    value = 0;
    ++++(*this);//start each hand with two cards
}

/**
 * Destructor
 * deletes dynamically allocated Card *card[] pointers
 */
Hand::~Hand() {
    /** Delete each card */
    for (int i = 0; i < number_of_cards; i++)
        delete cards[i];
}

/**
 * updates total value of hand by adding all initial values
 * where Ace = 11 and then subtracting 10 for number_of_aces
 * until value < 21 or number_of_aces = 0
 */
void Hand::updateValue() {
    int temp_value = 0;
    int temp_number_of_aces = number_of_aces;
    for (int i = 0; i < number_of_cards; i++) {
        temp_value = temp_value + cards[i]->getValue();
    }
    while ((temp_number_of_aces > 0) && (temp_value > 21)) {
        temp_value -= 10;
        --temp_number_of_aces;
    }
    value = temp_value;
}

/**
 * Add a card to the hand
 * @return pointer to (*this) object
 */
Hand & Hand::operator++() {
    Card *random_card = new Card();
    if (random_card->getValue() == 11) {
        ++number_of_aces;
    }
    cards[number_of_cards] = random_card;
    ++number_of_cards;
    updateValue();
    return (*this);
}

/** prints all types and values of hand */
void Hand::printHand() {
    std::string cards_string;
    for (int i = 0; i < number_of_cards; i++) {
        cards_string = cards_string + cards[i]->getType();
        if (i < number_of_cards - 1) {cards_string = cards_string + " ";}
    }
    std::cout << hand_holder << "'s hand is: " << cards_string << std::endl;
    std::cout << hand_holder << "'s hand value is " << value << "\n" << std::endl;
}

/** prints only first card (used for dealer) */
void Hand::printFirstCard() {
    std::cout << hand_holder << "'s first card is: " << cards[0]->getType() << "\n" << std::endl;
}

/** Overload comparison operators (>, <, ==) */
bool Hand::operator>(const Hand & rhs) const {return (value > rhs.value) ? true : false;}
bool Hand::operator>(int rhs) const {return (value > rhs) ? true : false;}
bool Hand::operator<(const Hand & rhs) const {return (value < rhs.value) ? true : false;}
bool Hand::operator<(int rhs) const {return (value < rhs) ? true : false;}
bool Hand::operator==(const Hand & rhs) const {return (value == rhs.value) ? true : false;}
bool Hand::operator==(int rhs) const {return (value == rhs) ? true : false;}
int Hand::getValue() {return value;}
int Hand::getNumber_of_cards() {return number_of_cards;}