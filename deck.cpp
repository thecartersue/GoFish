#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "deck.h"
#include "player.h"
#include "card.h"
using namespace std;

Deck::Deck() {
    myIndex = 0;
    int numRanks = 13;
    Card tempCard;
    for (int j = 0; j < numRanks; j++) {
        myCards[myIndex] = Card(j + 1, tempCard.spades);
        myIndex++;
    }
    for (int j = 0; j < numRanks; j++) {
        myCards[myIndex] = Card(j + 1, tempCard.hearts);
        myIndex++;
    }
    for (int j = 0; j < numRanks; j++) {
        myCards[myIndex] = Card(j + 1, tempCard.diamonds);
        myIndex++;
    }
    for (int j = 0; j < numRanks; j++) {
        myCards[myIndex] = Card(j + 1, tempCard.clubs);
        myIndex++;
    }
    myIndex = 51;
}
void Deck::shuffle() {
    //First create ordered set
    //Deck();
    int numCards = SIZE;
    //Set seed
    srand(time(NULL));
    //Swap cards
    for (int i = 0 ; i < numCards ; i++){
        int randomSwap = i + (rand() % (52 - i));
        swap(myCards[i], myCards[randomSwap]);
    }
}

Card Deck::dealCard() {
    if(myIndex>-1){
        Card tempCard;
        tempCard = myCards[myIndex];
        myIndex --;
        return (tempCard);
    }
}

int Deck::size() const {
    return (myIndex + 1);
}

void Deck::showDeck() {
    for ( int i = 0 ; i < myIndex + 1 ; i++){
        Card tempCard = myCards[myIndex-i];
        cout << tempCard.toString()  << ", ";
        if( i % 13  == 0){
            cout << "\n";
        }
    }
    cout << "\n" << "END OF SHOW DECK" << endl;
}

