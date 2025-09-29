//deck.h
#ifndef DECK_H
#define DECK_H

class Deck{

    public:
        Deck();
        void shuffle();
        void addCard();

    private:
        int cardCount_;
        int cards_[];

};

#endif 