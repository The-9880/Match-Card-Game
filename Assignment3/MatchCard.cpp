#include "MatchCard.h"

MatchCard::~MatchCard()
{

}

char MatchCard::charSuit()
{
	if (suit == HEARTS) return 'H';
	else if (suit == CLUBS) return 'C';
	else if (suit == DIAMONDS) return 'D';
	else return 'S';
}

char MatchCard::charRank()
{
	if (rank == ACE) return '1';
	else if (rank == N2) return '2';
	else if (rank == N3) return '3';
	else if (rank == N4) return '4';
	else if (rank == N5) return '5';
	else if (rank == N6) return '6';
	else if (rank == N7) return '7';
	else if (rank == N8) return '8';
	else if (rank == N9) return '9';
	else				 return '10';
}



std::ostream& operator<<(std::ostream& os, MatchCard& aCard)
{
	int rank = aCard.getRank();
	
	if (rank == 1)
		os << "Ace";
	else
		os << rank;

	switch (aCard.getSuit())
	{
	case 1:
		os << " of Spades";
		break;
	case 2:
		os << " of Hearts";
		break;
	case 3:
		os << " of Clubs";
		break;
	default:
		os << " of Diamonds";
	}

	return os;
}