#pragma once
#include "Queue.h"
#include "Stack.h"
#include "MatchPlayer.h"

#define STARTING_CARDS 6


class MatchGame
{

private:
	Stack<MatchCard> faceUp;	//	the faceup stack in the middle
	Queue<MatchCard> deck;		//	the deck of cards
	MatchCard* cards;			//	the initial array of cards
	MatchPlayer* players;		//	I'll use an array to keep track of my players in the game.
	int numOfPlayers;			//	A way to refer to the number of players outside of the scope of the constructor.
	int numCards;				//	Holds onto the number of cards we've generated for this game.


public:
	MatchGame(int numToPlay, int maxRank);	//	Initialize game with numToPlayer plays and maxRank for the maximum rank of card.

	void reformDeck();						//	The function to reform the deck in case it runs out, meant to be called when the deck is empty.
	void printFaceUp() const;				//	Prints the current face-up card on the stack.
	bool hasWon(MatchPlayer& player) const;	//	Tells us if a given player has won.
	void play();							//	Function that does the looping, calls other member functions to simulate gameplay, etc.

};