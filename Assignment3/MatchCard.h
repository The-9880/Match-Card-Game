#pragma once
#include <iostream>
#include <ctime>

enum Suit {SPADES = 1, HEARTS = 2, CLUBS = 3, DIAMONDS = 4};
enum Rank {ACE = 1, N2=2, N3=3, N4=4, N5=5, N6=6, N7=7, N8=8, N9=9, N10=10};

class MatchCard
{

private:
	Rank rank;
	Suit suit;
	friend std::ostream& operator<<(std::ostream& os, MatchCard& aCard);

public:
	MatchCard(Suit s, Rank r) : suit(s), rank(r) {}
	MatchCard() {}
	~MatchCard();

	inline Suit getSuit() { return suit; };
	inline Rank getRank() { return rank; };
	char charSuit();
	char charRank();


};

//	Greater-than comparison
inline bool operator>(MatchCard& thisCard, MatchCard& aCard)
{
	if (thisCard.getSuit() == aCard.getSuit())
		return thisCard.getRank() > aCard.getRank();
	else
		return thisCard.getSuit() > aCard.getSuit();
}

//	Less-than comparison
inline bool operator<(MatchCard& thisCard, MatchCard& aCard)
{
	if (thisCard.getSuit() == aCard.getSuit())
		return thisCard.getRank() < aCard.getRank();
	else
		return thisCard.getSuit() < aCard.getSuit();
}


//	Equivalence comparison	--	This doesn't check to see if the two cards are the same but checks if we have a 'match'
//	as per the definition of a 'match' in a game of MATCH. (Either the rank is equivalent or the suit is).
inline bool operator==(MatchCard& thisCard, MatchCard& aCard)
{
	return (thisCard.getRank() == aCard.getRank() || thisCard.getSuit() == aCard.getSuit());
}
