#include <iostream>
#include "MatchGame.h"

int main()
{

	int numPlayers, maxRank;

	std::cout << "Welcome to MATCH" << std::endl;
	std::cout << "\nEnter the number of players: ";
	std::cin >> numPlayers;

	std::cout << "\n\nEnter the maximum card rank for this game: ";
	std::cin >> maxRank;

	//	Perform validity check
	//	Given that each player must be given 6 cards at the beginning, and 1 card has to be placed face-up in the middle
	//	We know that we need a minimum of 6*numplayers + 1 cards.
	//	Therefore, 4 * maxRank must be >= to this quantity.
	while ((4 * maxRank) < ((6 * numPlayers) + 1))
	{
		std::cout << "\nThe maximum rank you've chosen is insufficient for a game with these many players. Choose again: ";
		std::cin >> maxRank;
		std::cout << std::endl;
	}


	MatchGame game(numPlayers, maxRank);

	std::cout << "Start" << std::endl;
	game.play();

	system("pause");
	return 0;
}