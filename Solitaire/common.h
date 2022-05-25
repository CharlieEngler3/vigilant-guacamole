//---INCLUDES---//
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>

//---CLASS DEFINITIONS---//
class Card
{
	public:
		Card(int suit, int rank);
		void DisplayCard(int suit, int rank);
		int GetSuit();
		int GetRank();
	
	private:	
		int suit, rank;
};

class Board
{
	public:
		Board();
		void DisplayBoard(Card* stacks[7][13], bool visible_cards[7][13], Card* pile[24]);

	private:
		void InitializeBoard(Card* stacks[7][13], bool visible_cards[7][13], Card* pile[24]);
		int CountUnderCards(Card* stacks[7][13], int column);

		Card* stacks[7][13];
		bool* visible_cards[7][13];
		Card* pile[24];
};
