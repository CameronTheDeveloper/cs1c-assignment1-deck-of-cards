#include "card.h"
#include <iostream>

// Implementation of helper functions for conversion
std::string suitToString(int s) {
    switch (s) {
        case SUIT_CLUBS: return "Clubs";
        case SUIT_DIAMONDS: return "Diamonds";
        case SUIT_HEARTS: return "Hearts";
        case SUIT_SPADES: return "Spades";
    }
    return "INVALID_SUIT"; 
}

std::string rankToString(int r) {
    switch (r) {
        case 1: return "A";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        // Handle ranks 2 through 10
        default: return std::to_string(r);
    }
}

// Card Constructor (using default values for C-style array initialization)
Card::Card(int s, int r) : suit_(s), rank_(r) {}

// Returns a string representation of the card (e.g., "A of Spades")
std::string Card::toString() const {
    return rankToString(rank_) + " of " + suitToString(suit_);
}

// Checks if two cards are identical
bool Card::operator==(const Card& other) const {
    return (suit_ == other.suit_) && (rank_ == other.rank_);
}
