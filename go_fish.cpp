// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void inputPlayers(int numPlayers);
int main( ) {
    ofstream myFile;
    myFile.open ("gofish_results.txt");
    if (myFile.is_open()){
        cout << "All results are in the Text File";
    }else{
        cout << "Error opening file";
    }

    myFile << "Game played all the way to the end" << endl;
    //Set numCards each player gets and numPlayers
    int numCards = 12;
    if(numCards > 52/2){
        myFile << "Cards dealt wrong.";
        return EXIT_SUCCESS;
    }
    int books = 0;
    int rank = 0;
//    int numPlayers = 0;
//    cin >> numPlayers;

    //Instantiate players
    Player p1("Khalid");
    Player p2("Zane");

    //Create a deck of cards
    Deck d;
    //d.showDeck();
    d.shuffle();
    //d.showDeck();

    //deal first hand
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    //Initial hands
    myFile << p1.getName() << " has : " << p1.showHand() << endl;
    myFile << p2.getName() << " has : " << p2.showHand() << endl;

    //Begin Game
    bool playGame = true;
    myFile << "Let the Games Begin\n" << endl;
    //Card declarations
    Card playCard;
    Card playCard2;
    //check if pairs exist at beginning of game
    while (p1.checkHandForPair(playCard, playCard2)) {
        p1.bookCards(playCard, playCard2);
    }
    while (p2.checkHandForPair(playCard, playCard2)) {
        p2.bookCards(playCard, playCard2);
    }

    while (playGame) {
        //selecting a card from player 1
        if (p1.getHandSize() != 0) {
            playCard = p1.chooseCardFromHand();
            //getting the rank of this card
            rank = playCard.getRank();
            //debug stuff
            //cout << "Khalid: " << p1.showHand() << endl;
            //cout << "Zane: " << p2.showHand() << endl;
            //Asking opponent if they have that rank (Print statement)
            myFile << p1.getName() << " asks - Do you have a " << playCard.rankString(rank) << "." << endl;
            //check if opponent has card
            if (p2.cardInHand(playCard)) {
                //AT THIS POINT opponent has card
                //Player 1 will book this rank.
                myFile << p2.getName() << " says - Yes. I have a " << playCard.rankString(rank) << "." << endl;
                //Remove card from opponents hand and put into secondary card
                playCard2 = p2.removeCardFromHand(playCard);
                //book the card you had in hand and the opponents card
                p1.bookCards(playCard, playCard2);
                //Print booked cards
                myFile << p1.getName() << " books " << playCard.toString() << " and " << playCard2.toString() << "."
                     << endl;
            } else {
                //AT THIS POINT opponent did not have card you asked for
                //Player 1 will take a card from the deck
                //PLayer 2 says GO FISH
                myFile << p2.getName() << " says - Go Fish." << endl;
                //declare the card to be added and remove from deck
                Card addCard1 = d.dealCard();
                p1.addCard(addCard1);
                myFile << p1.getName() << " draws " << addCard1.toString() << "." << endl;
                if (p1.checkHandForPair(playCard, addCard1)) {
                    p1.bookCards(playCard, addCard1);
                    myFile << p1.getName() << " books " << playCard.toString() << " and " << addCard1.toString() << "."
                         << endl;
                }
            }
        } else {
            if (d.size() != 0) {
                Card addCard1 = d.dealCard();
                p1.addCard(addCard1);
                myFile << p1.getName() << " draws " << addCard1.toString() << "." << endl;
                if (p1.checkHandForPair(playCard, addCard1)) {
                    p1.bookCards(playCard, addCard1);
                    myFile << p1.getName() << " books " << playCard.toString() << " and " << addCard1.toString() << "."
                         << endl;
                }
            }
        }
///////////////////////////////////////////////////////////
        //debug stuff
        //books = p1.getBookSize() + p2.getBookSize();
        //cout << "\nBooks: " << books << endl;
        //cout << "Size of Deck: " << d.size() << endl;
        myFile << endl;
////////////////////////////////////////////////////////////
        if (p2.getHandSize() != 0) {
            //selecting a card from player 2
            playCard = p2.chooseCardFromHand();
            //getting the rank of this card
            rank = playCard.getRank();
            //Asking opponent if they have that rank (Print statement)
            myFile << p2.getName() << " asks - Do you have a " << playCard.rankString(rank) << "." << endl;
            //check if opponent has card
            if (p1.cardInHand(playCard)) {
                //AT THIS POINT opponent has card
                //Player 2 will book this rank.
                myFile << p1.getName() << " says - Yes. I have a " << playCard.rankString(rank) << "." << endl;
                //Remove card from opponents hand and put into secondary card
                playCard2 = p1.removeCardFromHand(playCard);
                //book the card you had in hand and the opponents card
                p2.bookCards(playCard, playCard2);
                //Print booked cards
                myFile << p2.getName() << " books " << playCard.toString() << " and " << playCard2.toString() << "."
                     << endl;
            } else {
                //AT THIS POINT opponent did not have card you asked for
                //Player 1 will take a card from the deck
                //PLayer 2 says GO FISH
                myFile << p1.getName() << " says - Go Fish." << endl;
                //declare the card to be added and remove from deck
                Card addCard2 = d.dealCard();
                p2.addCard(addCard2);
                myFile << p2.getName() << " draws " << addCard2.toString() << "." << endl;
                if (p2.checkHandForPair(playCard, addCard2)) {
                    p2.bookCards(playCard, addCard2);
                    myFile << p2.getName() << " books " << playCard.toString() << " and " << addCard2.toString() << "."
                         << endl;
                }
            }
        } else {
            if (d.size() != 0) {
                Card addCard2 = d.dealCard();
                p2.addCard(addCard2);
                myFile << p2.getName() << " draws " << addCard2.toString() << "." << endl;
                if (p2.checkHandForPair(playCard, addCard2)) {
                    p2.bookCards(playCard, addCard2);
                    myFile << p2.getName() << " books " << playCard.toString() << " and " << addCard2.toString() << "."
                         << endl;
                }
            }
        }
        if (p1.getBookSize() + p2.getBookSize() == 26) {
            if (p1.getBookSize() > p2.getBookSize()) {
                myFile << "Khalid wins";
            } else
            if(p2.getBookSize() > p1.getBookSize()){
                myFile << "Zane wins";
            }
            else myFile << "Its a tie";
            playGame = false;
        }
        //debug stuff
        //books = p1.getBookSize() + p2.getBookSize();
        //cout << "\nBooks: " << books << endl;
        //cout << "Size of Deck: " << d.size() << endl;
        //d.showDeck();
        myFile << "\n";
    }
    myFile.close();
    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}




/*
void inputPlayers(int numPlayers){
    for(int i = 1 ; i < numPlayers + 1 ; i ++){
        string mystr;
        string playerDeclaration = "p" + to_string(i);
        Player playerDeclaration(getline(cin, mystr));
    }
}
 */
