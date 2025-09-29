#include "deck.h"
#include <iostream>
#include <algorithm>

int main() {
    std::cout << "Welcome to Card Shuffler!" << std::endl;
    // Initialize the two decks: 
    Deck originalDeck;
    originalDeck.initializeDeck();

    // Note: When creating a copy of an array-based class, the default
    // copy constructor performs a shallow copy of the array members,
    // which is the desired behavior here (copying each Card object).
    Deck currentDeck = originalDeck; 

    std::cout << "--- C++ Assignment 1: Deck of Cards Perfect Shuffle ---\n\n";

    // 3. Print out the initial deck
    std::cout << "1. Initial Deck Configuration:\n";
    originalDeck.printDeck();

    // 4. Calculate shuffles necessary to return to original configuration
    int shuffleCount = 0;
    
    // Loop until the current deck state matches the original deck state
    do {
        currentDeck.perfectShuffle();
        shuffleCount++;

        if (shuffleCount == 1) {
            // 3. Print out the deck after the first perfect shuffle
            std::cout << "\n2. Deck After 1st Perfect Shuffle:\n";
            currentDeck.printDeck();
        }
    } while (!currentDeck.compareDecks(originalDeck));

    // 3. Print out the final deck (which is the same as the original)
    std::cout << "\n3. Final Deck Configuration (Returned to Original):\n";
    currentDeck.printDeck();

    std::cout << "\n======================================================\n";
    std::cout << "RESULT: It took " << shuffleCount << " perfect shuffles to return the deck to its original configuration.\n";
    std::cout << "======================================================\n";

    return 0;
}
