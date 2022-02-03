#include <iostream>
#include <vector>
#include <algorithm>
#pragma once
using namespace std;

vector<string> suit = {"Clubs", "Diamonds", "Hearts", "Spades"};
vector<int> face = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

//A class for the faces and suits
class Card {
  private:
	int Face;
	string Suit;
  public:
	//Constructor
	Card(int new_face, string new_suit) {
		Face = new_face;
		Suit = new_suit;
		//Quitting the program if faces or suits are invalid
		if (Face < 1 or Face > 13) exit(1);
		//This will start at the beginning of the vector, all the way to the end. Searches for the value of new_suit. If it fails, it returns the end iterator.
		if (find(suit.begin(), suit.end(), new_suit) == suit.end()) exit(1);
	}


	//Getters for getting the face and suit
	int get_Face() {
		return Face;
	}

	string get_Suit() {
		return Suit;
	}

	void print() {
		if (get_Face() == 1) cout << "Ace of ";
		else if (get_Face() == 11) cout << "Jack of ";
		else if (get_Face() == 12) cout << "Queen of ";
		else if (get_Face() == 13) cout << "King of ";
		else cout << get_Face() << " of ";
		cout << get_Suit() << endl;
	}

};
