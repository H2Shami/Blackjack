//Shami Walkup
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include "deck.h"
#include "hand.h"
#include "card.h"
using namespace std;

void die() {
	cout << "BAD INPUT!" << endl;
	exit(0);
}

int main() {
	cout << endl;
	system("clear");
	const int blackjack = 21, min_money = 5, max_money = 1000;
	int dealer = 0;

	//Input number of players while checking for bad input
	int p = 0;
	cout << "Welcome to Blackjack! Please enter the number of people playing:\n";
	cin >> p;
	if (!cin or p < 0) die();
	cout << endl;
	vector<Hand> playerHand;		// The dealer's hand will also be stored here
	vector<int> playerCash(p);
	vector<int> playerBet(p);
	for (int i = 0; i < p; i++) playerCash.at(i) = 100;		//Given the boys some money to gamble with
	for (int i = 0; i < p + 1; i++) { 
		Card card(2, "Clubs");
		Hand temp(card); 
		playerHand.push_back(temp);
//		playerHand.at(i).print();
	}

	Deck deck;
	//Printing card class
//	card.print();

	//Playing the game
	while (true) {
		cout << "Please enter a random seed for the shuffle!" << endl;
		int seed = 0;
		cin >> seed;
		if (!cin) die();
		deck.shuffle(seed);


//Asking the player how much to wager
		for (int i = 0; i < p; i++) {
			int bet = 0;
			while (true) {
			cout << "Wager amount for Player " << i + 1 << ": (You have " << playerCash.at(i) << "$)\n";
			cin >> bet;
			if (!cin) die();
			if (bet < min_money) {
				cout << "Wager is too low." << endl;
				continue;
			}
			if (bet > playerCash.at(i)) {
				cout << "Wager is too high." << endl;
				continue;
			}
			else break;
			}
			playerBet.at(i) = bet;
			playerCash.at(i) -= bet;
		}
//Dealing begins
		for (int i = 0; i < p + 1; i++) {
			playerHand.at(i).clear();
		}
			cout << "Dealing hands..." << endl;
		for (int i = 0; i < p + 1; i++) {	//p + 1 instead of p because the dealer needs some cards too
			if (i == p) {
				Card temp = deck.deal();
				playerHand.at(i).addCard(temp);
				continue;
			}
			for (int j = 0; j < 2; j++) {					//2 because that's how many cards you get in blackjack
				Card temp = deck.deal();
//				temp.print();
				playerHand.at(i).addCard(temp);
			}
		}
//Results from dealing
		for (size_t i = 0; i < playerHand.size(); i++) {
			if (i == playerHand.size() - 1) {
				cout << "The Dealer's Card: " << endl;
				playerHand.back().print();
				cout << "Total: " << playerHand.back().total() << endl;
				continue;
			}
			cout << "Player " << i + 1 << "'s cards: \n";
			playerHand.at(i).print();
			cout << "Total: " << playerHand.at(i).total() << endl;
		}
//Players begin to play
		for (int i = 0; i < p; i++) {
			bool turn = true;
			string choice;
			while (turn) {
				if (playerHand.at(i).total() != blackjack) {
				cout << "Player " << i + 1 << " would you like to hit or stand? (Input \"HIT\" or \"STAND\")" << endl;
				cin >> choice;
				if (choice == "HIT") {
					Card temp = deck.deal();
					playerHand.at(i).addCard(temp);
					playerHand.at(i).print();
					cout << "Total: " << playerHand.at(i).total() << endl;
				} else if (choice == "STAND") {
					turn = false;
				}
				else die();
				if (playerHand.at(i).total() > blackjack) turn = false;
			}
				else {
					cout << "BLACKJACK!" << endl;
					turn = false;
				}
			}
		}
//Dealer's Turn
		bool turn = true;
		cout << "The Dealer's cards are:" << endl;
		Card temp = deck.deal();
		playerHand.back().addCard(temp);
		while (turn) {
			temp = deck.deal();
			cout << "Dealer's cards: " << endl;
			playerHand.back().print();
			if (playerHand.back().total() > 17) turn = false;
			else if (playerHand.back().total() < blackjack) playerHand.back().addCard(temp);
		}
//Determining what will happen at the end of a round
		for (int i = 0; i < p; i++) {
//Scorekeeping
			if (playerHand.at(i).total() == blackjack) playerCash.at(i) += playerBet.at(i) * 2;
			else if (playerHand.at(i).total() == playerHand.back().total()) playerCash.at(i) += playerBet.at(i);	//The last hand in the vector is the dealer's
			else if (playerHand.at(i).total() > playerHand.back().total()) playerCash.at(i) += playerBet.at(i) * 1.5;
//Eliminating a player below $5
			if (playerCash.at(i) < min_money) {
				cout << "Player " << i << " has no more money to bet with." << endl;
				playerHand.erase(playerHand.begin() + i);
				playerCash.erase(playerCash.begin() + i);
				playerBet.erase(playerBet.begin() + i);
				p--;
			}
//Declaring the winner of someone with more than $1000, quit the game
			else if (playerCash.at(i) > max_money) {
				cout << "Winner: Player " << i + 1 << ". Game over!\n";
				exit(0);
			}
		}
	}


}





/*									CODE GRAVEYARD

			class Player {
				Hand h;
				int money;
			public:
				Player (Hand newHand, int newmoney) {
					h = newHand;
					money = newmoney;
				}
				int get_money() {
					return money;
				}
			};

			const int money_starter = 100;
			assert(("Invalid input! Try again!", p > 0)); //Number of players must be greater than zero.

			system.clear();

			for (int p : player) {
			player.push_back();
			cout << "Player " << p << ": $" << money << endl;
			cout <<
			cout << endl;
			}

			assert(("Wager is too low! Please input a different value!", bet > min_money))
			assert(("Wager is too high! Please input a different value!", bet < money.at()))

		    if (player goes over 21) money.at(p) -= bet;
		    else if (dealer goes over 21) money.at(p) += bet;
		    else if (player and dealer goes over 21) {
		        cout << "Player " << p.at() << " has busted!\n";
		        elimination();
		    }

		if (dealer > money.at(p)) money -= bet;
		else if (dealer < money.at(p)) {
			money += bet;
			dealer += bet;
		} else continue;

*/
