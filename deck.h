#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "card.h"
#pragma once
using namespace std;

class Deck {
	vector<Card> deck;	//Make it a vector of numbers 1-52 and give the numbers names
  public:
	void shuffle(int seed) {
		srand(seed); 
		deck.clear();
		for (int i = 0; i < 52; i++) {		//Create each of the 52 cards
			int face = 0; 
			string suit;
			if (i < 13) suit = "Spades";		//Make suits of 13 cards each
			else if (i < 26) suit = "Clubs";
			else if (i < 39) suit = "Diamonds";
			else if (i < 52) suit = "Hearts";
			face = (i % 13) + 1;		//Get the face value of the card instead of the location in the vector
			Card temp = {face, suit};
			deck.push_back(temp);		//Add the new card
		}
		random_shuffle(deck.begin(), deck.end());	//Shuffle the deck
	}
	Card deal() {		//Take one card from the back and deal it
		Card temp = deck.back();	
		deck.pop_back();	
		return temp;
	}
};
