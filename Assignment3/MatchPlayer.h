#pragma once
#include <String>
#include "OrderedList.h"
#include "MatchCard.h"

class MatchPlayer
{

private:
	std::string name;
	OrderedList<MatchCard, lessThan> hand;
	friend std::ostream& operator<<(std::ostream& os, MatchPlayer& player);
	static int numPlayers;		//	Keeps track of the number of players throughout the game.
								//	The static variable isn't really a necessity but I'll keep it around for a different possible implementation

public:
	MatchPlayer();
	MatchPlayer(std::string nameGiven) : name(nameGiven) {}
	~MatchPlayer() { numPlayers--; };

	std::string getName() const;
	bool hasMatch(MatchCard& aCard) const;		//	Function that checks if there's a match for the given card.
	void pickUpCard(MatchCard aCard);			//	Act of picking up a card
	MatchCard discard(unsigned int pos);		//	Act of removing a card from hand.
	int cardCount() const;						//	Count how many cards in hand - we'll call a win when this returns 0.
	MatchCard getFromHand(unsigned int i);		//	Return a copy of a particular card from hand.
	int indexOfMatch(MatchCard& aCard) const;	//	Returns the index of a matching card. PRECONDITON: Only called after a match is found.

};

//	Ostream operator
inline std::ostream& operator<<(std::ostream& os, MatchPlayer& player)
{
	for (int i = 1; i <= player.hand.getLength(); ++i)
	{
		os << player.hand.retrieve(i) << std::endl;
	}

	return os;
}