#include "MatchGame.h"

MatchGame::MatchGame(int numToPlay, int maxRank)
{
	numOfPlayers = numToPlay;
	numCards = 4 * maxRank;

	//	We'll begin initializing the game here.
	players = new MatchPlayer[numToPlay];	//	This automatically creates the amount of players we want and the MatchPlayer constructor ensures
											//	their names as 'Player 1' ... 'Player n'.

	cards = new MatchCard[numCards];	//	Creating the array for 4 * maxRank MatchCards

	int cardCount = 0;						//	I'll be using cardCount to track the number of cards in the deck.
	for (Suit mySuit = SPADES; mySuit <= 4; mySuit = Suit(mySuit + 1))		//	Iterate over the Suit enum
	{

		for (Rank myRank = ACE; myRank <= maxRank; myRank = Rank(myRank + 1))	//	Iterate over the Rank enum
		{
			//	Create new cards and add them to the array.
			cards[cardCount] = MatchCard(mySuit, myRank);						//	Add the card to my array of cards.
			cardCount++;														//	Increment the count.
		}
	}

	//	Placing the array of cards randomly into the deck queue
	std::srand(std::time(0));
	for (int i = 0; i < 100; ++i)	//	To randomize the order of cards in the array, I'm going to swap random pairs 100 times 
	{								//	Then I'll just sequentially place them into the deck.
		int idx1 = std::rand() % cardCount;
		int idx2 = std::rand() % cardCount;

		MatchCard temp = cards[idx1];

		cards[idx1] = cards[idx2];
		cards[idx2] = temp;
	}

	//	Now I can sequentially draw the cards from the array into the deck.
	for (int i = 0; i < cardCount; ++i)	
	{
		deck.enqueue(cards[i]);
	}

	delete[] cards;						//	I don't need the initial cards array anymore
	cards = nullptr;

	//	Now to give the players their hands.
	//	I prefer to deal out a card to everyone before giving anyone a second, third, ..., nth card, so that's how I'll deal here.
	for (int i = 0; i < STARTING_CARDS; ++i)
	{
		for (int j = 0; j < numToPlay; ++j)
		{
			players[j].pickUpCard(deck.dequeue());
			cardCount--;	//	Keeping track of how many cards in the deck.
		}
	}

	//	The traditional beginning of most card games is when the middle face-up card is in place:
	faceUp.push(deck.dequeue());
}

void MatchGame::printFaceUp() const
{
	std::cout << "The face-up card is: " << faceUp.peek() << std::endl;
}

bool MatchGame::hasWon(MatchPlayer& player) const
{
	return (player.cardCount() == 0);
}

void MatchGame::reformDeck()
{
	MatchCard temp = faceUp.pop();				//	I'm saving the original face-up card - all others below are going back into the deck

	MatchCard* cards = new MatchCard[numCards];	//	I'm going to place the faceUp cards into an array to randomly draw from again
												//	to simulate shuffling the cards before reforming them into the deck.
	int tempCount = 0;
	while (!faceUp.isEmpty())
	{
		cards[tempCount] = faceUp.pop();		//	tempCount was creating for indexing purposes, and to count how many are in faceUp.
		tempCount++;							//	By the end, tempCount will be 1 greater than the last assigned index of cards.
	}

	//	Placing the array of cards randomly into the deck queue	--	Repeating my random-shuffle from the constructor.
	std::srand(std::time(0));
	for (int i = 0; i < 100; ++i)	//	To randomize the order of cards in the array, I'm going to swap random pairs 100 times 
	{								//	Then I'll just sequentially place them into the deck.
		int idx1 = std::rand() % tempCount;
		int idx2 = std::rand() % tempCount;

		MatchCard temp = cards[idx1];

		cards[idx1] = cards[idx2];
		cards[idx2] = temp;
	}

	//	Now I can sequentially draw the cards from the array into the deck.
	for (int i = 0; i < tempCount; ++i)
	{
		deck.enqueue(cards[i]);
	}
	
	//	The previous steps so far have reformed the deck.
	delete[] cards;
	cards = nullptr;
	
	faceUp.push(temp);	//	And this should put the top-most faceUp card back in its position, where it should be.

	std::cout << "\nThe deck has been repopulated.\n";
}

void MatchGame::play()
{
	//	This is where the game actually runs its course.
	printFaceUp();

	bool foundWinner = false;
	int winningPlayer = -1;			//	This value will be reassigned to the index of the winning player.

	while (!foundWinner)			//	While no one has won the game, continue the turn-based gameplay
	{
		for (int i = 0; i < numOfPlayers; ++i)		//	Loop over the players so they can do their turns
		{
			//	Perform checks to make sure the player can go ahead with their turn
			if (deck.isEmpty())
				reformDeck();

			std::cout << "\n\nIt is " << players[i].getName() << "'s turn.\n";
			std::cout << "His cards: \n" << players[i] << std::endl;			//	NOTE: This is so the player's hand is visible for assessment
																				//	purposes. Can be commented/uncommented as needed.
			//	Check for matches
			if (players[i].hasMatch(faceUp.peek()))
			{
				//	Match found!
				std::cout << players[i].getName() << " has found a match! They played " << players[i].getFromHand(players[i].indexOfMatch(faceUp.peek())) << std::endl;
				
				//	The player can now discard that card by placing it in the middle
				faceUp.push(players[i].discard(players[i].indexOfMatch(faceUp.peek())));
			}
			else
			{
				//	No match found -- pick up a card.
				players[i].pickUpCard(deck.dequeue());
				std::cout << players[i].getName() << " did not find a match. They drew a card." << std::endl;
			}

			//	Perform post-turn checks.
			if (players[i].cardCount() == 0)			//	Note: I'm aware that I could replace the while statement's condition with 'true'
			{										//	since I break the loop manually, but chose not to for a different possible implementation.
				winningPlayer = i;
				foundWinner = true;
				break;
			}

			if (players[i].cardCount() == 1)
				std::cout << players[i].getName() << " yells Last-card!" << std::endl;
		}
	}

	std::cout << "\n\n" << players[winningPlayer].getName() << " has crushed their enemies in MATCH (not even close)" << std::endl;
}


//		----	REMOVED IMPLEMENTATIONS

/*	--	This was my old implementation for randomly drawing cards from the initial cards array.
std::srand(std::time(0));
for (int i = 0; i < cardCount; ++i)
{
List<int> used;			//	This will hold the indices that we've used -- we'll use this to make sure we don't draw the same card twice.

int idx = std::rand() % cardCount;

while (used.find(idx) != -1)	//	This is likely not the most efficient method possible - I'm brute-forcing to find an index I
{								//	haven't used yet. I did it because I don't like the idea of repeatedly re-forming the cards array
idx = std::rand() % cardCount;	//	each time I draw a card.
}

std::cout << idx << std::endl;

deck.enqueue(cards[idx]);
used.append(idx);
}
*/