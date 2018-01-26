#include "MatchPlayer.h"

int MatchPlayer::numPlayers = 0;

MatchPlayer::MatchPlayer()
{
	numPlayers++;

	name = "Player " + std::to_string(numPlayers);
}

std::string MatchPlayer::getName() const
{
	return name;
}

bool MatchPlayer::hasMatch(MatchCard& aCard) const
{
	//	Look through all the cards and find a match

	return (hand.find(aCard) != -1);
}

MatchCard MatchPlayer::discard(unsigned int pos)
{
	return hand.remove(pos);
}

void MatchPlayer::pickUpCard(MatchCard aCard)
{
	hand.insert(aCard);
}

int MatchPlayer::cardCount() const
{
	return hand.getLength();
}

MatchCard MatchPlayer::getFromHand(unsigned int i)
{
	return hand.retrieve(i);
}

int MatchPlayer::indexOfMatch(MatchCard& aCard) const
{
	return hand.find(aCard);
}