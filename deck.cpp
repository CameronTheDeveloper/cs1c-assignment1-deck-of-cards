#include "deck.h"
#include <iostream>
#include <algorithm> // Required for std::equal

Deck::Deck() {
    // The C-style array is automatically allocated on the stack/heap, 
    // depending on where the Deck object is created.
    // The Card default constructor is implicitly called for all 52 elements.
}

// Method to Initialize the Deck of Cards
void Deck::initializeDeck() {
    int cardIndex = 0;
    
    // Loop through suits (0 to 3)
    for (int s = SUIT_CLUBS; s < TOTAL_SUITS; ++s) {
        // Loop through ranks (1 to 13)
        for (int r = RANK_ACE; r <= RANK_KING; ++r) {
            // Assign the new Card directly to the array index
            cards_[cardIndex++] = Card(s, r);
        }
    }
}

// Method to Perform a Perfect Shuffle (In-Shuffle)
void Deck::perfectShuffle() {
    // Use a temporary C-style array to construct the new, shuffled state
    Card newCards[DECK_SIZE];
    
    const int halfSize = DECK_SIZE / 2; // 26

    // Interleave the two halves: Card 1, Card 27, Card 2, Card 28, ...
    for (int i = 0; i < halfSize; ++i) {
        // Assign card from first half (Index 0 to 25) to even position in new array
        newCards[i * 2] = cards_[i];
        
        // Assign card from second half (Index 26 to 51) to odd position in new array
        newCards[i * 2 + 1] = cards_[i + halfSize];
    }

    // Copy the contents of the temporary array back to the main deck array
    for (int i = 0; i < DECK_SIZE; ++i) {
        cards_[i] = newCards[i];
    }
}

// Method to Print the Deck of Cards
void Deck::printDeck() const {
    std::cout << "-------------------- Deck Content (52 Cards) --------------------\n";
    for (int i = 0; i < DECK_SIZE; ++i) {
        std::cout << "[" << i + 1 << "]: " << cards_[i].toString();
        
        // Print 4 cards per line for readability
        if ((i + 1) % 4 == 0) {
            std::cout << "\n";
        } else {
            std::cout << "\t"; 
        }
    }
    std::cout << "\n-----------------------------------------------------------------\n";
}

// Method to Compare Two Decks of Cards
bool Deck::compareDecks(const Deck& other) const {
    // Use std::equal to compare the two C-style arrays efficiently
    return std::equal(std::begin(cards_), std::end(cards_), std::begin(other.cards_));
}
