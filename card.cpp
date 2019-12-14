#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "deck.h"
#include "player.h"
#include "card.h"
using namespace std;

Card::Card() {
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    std::string outputRank;
    std::stringstream ss;
    ss << myRank;
    switch(myRank){
        case 1: outputRank = "A";
            break;
        case 11: outputRank = "J";
            break;
        case 12: outputRank = "Q";
            break;
        case 13: outputRank = "K";
            break;
        default: outputRank = ss.str();
    }

    string outputSuit;
    switch(mySuit){
        case 0: outputSuit = "s";
            break;
        case 1: outputSuit = "h";
            break;
        case 2: outputSuit = "d";
            break;
        case 3: outputSuit = "c";
            break;
    }
    return (outputRank + outputSuit);
}

bool Card::sameSuitAs(const Card &c) const {
    return (mySuit == c.mySuit);
}

int Card::getRank() const {
    return (myRank);
}

string Card::suitString(Card::Suit s) const {
    string outputSuit;
    switch(mySuit){
        case 0: outputSuit = "s";
            break;
        case 1: outputSuit = "h";
            break;
        case 2: outputSuit = "d";
            break;
        case 3: outputSuit = "c";
            break;
    }
    return (outputSuit);
}

string Card::rankString(int r) const {
    std::string outputRank;
    std::stringstream ss;
    ss << myRank;
    switch(myRank){
        case 1: outputRank = "A";
            break;
        case 11: outputRank = "J";
            break;
        case 12: outputRank = "Q";
            break;
        case 13: outputRank = "K";
            break;
        default: outputRank = ss.str();
    }
    return outputRank;
}

bool Card::operator==(const Card &rhs) const {
    return (this->toString() == rhs.toString());
}

bool Card::operator!=(const Card &rhs) const {
    return (this->toString() != rhs.toString());
}

ostream& operator << (ostream& out, const Card& c){
    //   out << c;
    //   return out;
}





