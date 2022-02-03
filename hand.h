#include <iostream>
#include <algorithm>
#include <vector>
#include "card.h"
#pragma once
using namespace std;

class Hand {
	vector<Card> hand;		//For the hand we implement a vector of cards, since the expected size is small
	public:
	Hand(Card x) {			//Initialize the hand with the first card dealt to it
		hand.push_back(x);
	}
	void clear() {		//Reset the hand and get rid of the cards
		hand.clear();
	}
	void print() {			//Print every card in the hand by going through the vector one at a time
		for (size_t i = 0; i < hand.size(); i++) {
			hand.at(i).print();
		}
	}
	void addCard(Card temp) {		//Add the new card dealt to the vector
		hand.push_back(temp);
	}
	int total() {	//Get the total value of our hand
		int temp = 0;
		for (size_t i = 0; i < hand.size(); i++) {	//First count the card values without the Aces
			if (hand.at(i).get_Face() > 9) temp += 10;	//If its a face card, count it as 10
			else if (hand.at(i).get_Face() != 1) temp += hand.at(i).get_Face();	//If it's not the Ace, add the value
		}
		for (size_t i = 0; i < hand.size(); i++) {	//Now count the aces
			if (hand.at(i).get_Face() == 1 and temp < 11) temp+= 11;	//Now go back, if we see an Ace, add the value as 11 if possible
			else if (hand.at(i).get_Face() == 1) temp += 1;		//If adding as 11 will go over 21, make the value 1 and add
		}
		return temp;		//Return the final value
	}
	bool bust() {
		if (total() > 21) return true;	//21 is the max hand value of blackjack
		else return false;
	}
};
