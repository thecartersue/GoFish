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

Player::Player() {
    myName = "";
    myBook.clear();
    myHand.clear();
}
void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    if (c1.getRank() != c2.getRank()) {
        cout << "stop";
    }
    //first remove
    removeCardFromHand(c1);
    int sizeOfHand = 0;
    while(sizeOfHand < myHand.size()){
        if ( myHand[sizeOfHand] == c2){
            removeCardFromHand(c2);
        }
        sizeOfHand++;
    }
    //then book
    myBook.push_back(c1);
    myBook.push_back(c2);
}

//OPTIONAL
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards the make the pair.
bool Player::checkHandForBook(Card &c1, Card &c2) {
    for (int i = 0; i < myHand.size(); i++) {
        for (int j = 0; j < myHand.size(); j++) {
            if (myHand[i] != myHand[j]) {
                if (myHand[i].getRank() == myHand[j].getRank()) {
                    return true;
                }
            }
        }
    }
    return false;
}

//OPTIONAL
//comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if (c.getRank() == myHand[i].getRank()) {
            return true;
        }
    }
    return false;
}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const {
    //seed
    srand(time(NULL));
    //mod divider
    int divisor = myHand.size();
    //random number to divide by
    int random = rand();
    return (myHand[random%divisor]);
}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    for (int i = 0; i< myHand.size(); i++){
        if (myHand[i].getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}


//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c) {
    Card tempCard;
    for (int i = 0; i < myHand.size() ; i++) {
        if (myHand[i].getRank() == c.getRank()) {
            tempCard = myHand[i];
            myHand.erase(myHand.begin() + i);
            return tempCard;
        }
    }
}
/*
int index = 0;
while (myHand[index].getRank() != NULL) {
    if (c.toString() == myHand[index].toString()) {
        myHand.erase(myHand.begin() + index);
    }
    index++;
}
return c;
 */

//what cards does the player have?
string Player::showHand() const{
    int index = 0;
    string hand;
    for(std::vector<Card>::const_iterator it = myHand.begin() ; it != myHand.end(); ++it){
        hand =hand +  myHand[index].toString() + ",";
        index++;
    }
    return hand;
}


string Player::showBooks() const{
    int index = 0;
    string book;
    for(std::vector<Card>::const_iterator it = myHand.begin() ; it != myHand.end(); ++it){
        book =book +  myBook[index].toString() + ",";
        index++;
    }
    return book;
}

int Player::getHandSize() const{
    return myHand.size();
}

int Player::getBookSize() const {
    //books are multiples of two
    return (myBook.size() / 2);
}

bool Player::checkHandForPair(Card &c1, Card &c2){
    for(int i = 0 ; i < myHand.size() ; i ++ ){
        for(int j = 0 ; j < myHand.size() ; j++){
            if (myHand[i].getRank() == myHand[j].getRank()){
                if(myHand[i] != myHand[j]) {
                    c1 = myHand[i];
                    c2 = myHand[j];
                    return true;
                }
            }
        }
    }return false;
}


bool Player::sameRankInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i].getRank() == c.getRank()) {
            if (myHand[i] != c) {
                return true;
            }
        }
    }
    return false;
}





