#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <algorithm> // Needed for std::equal later

const int DECK_SIZE = 52; // Define the fixed size of the deck

class Deck {


    public:
        Deck();

        // 2. Initialize the deck of cards (create all 52 cards)
        void initializeDeck();

        // 2. Perform a perfect shuffle (interleave the two halves)
        void perfectShuffle();

        // 2. Print the deck of cards (formatted)
        void printDeck() const;

        // 2. Compare two decks of cards (to see if they are in the same order)
        bool compareDecks(const Deck& other) const;


    private:
        // Using a fixed-size C-style array instead of std::vector
        Card cards_[DECK_SIZE];

};

#endif
