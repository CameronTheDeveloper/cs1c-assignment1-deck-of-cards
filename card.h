#ifndef CARD_H
#define CARD_H

#include <string>

// --- Integer Constants for Suit and Rank ---

// Suits (0 to 3)
const int SUIT_CLUBS = 0;
const int SUIT_DIAMONDS = 1;
const int SUIT_HEARTS = 2;
const int SUIT_SPADES = 3;
const int TOTAL_SUITS = 4;

// Ranks (1 to 13)
const int RANK_ACE = 1;
const int RANK_KING = 13;
const int TOTAL_RANKS = 13;


// Helper functions for conversion (implemented in Card.cpp)
std::string suitToString(int s);
std::string rankToString(int r);

class Card {
private:
    // Now using int to represent suit and rank
    int suit_;
    int rank_;

public:
    // Constructor
    Card(int s, int r);

    // Methods
    std::string toString() const;

    // Overload the equality operator for comparison
    bool operator==(const Card& other) const;
};

#endif
