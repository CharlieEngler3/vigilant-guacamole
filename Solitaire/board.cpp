#include "common.h"

const std::string suits[4] = { "♡", "♧", "◇", "♤" };
const std::string suit_names[4] = { "Hearts", "Clubs", "Diamonds", "Spades" };

const std::string ranks[15] = { "R", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
const std::string rank_names[15] = { "Joker", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };

Board::Board()
{
	Card* stacks[7][13];
	bool visible_cards[7][13];

	Card* pile[24];

	InitializeBoard(stacks, visible_cards, pile);
}

void Board::InitializeBoard(Card* stacks[7][13], bool visible_cards[7][13], Card* pile[24])
{
	for(int y = 0; y < 13; y++)
	{
		for(int x = 0; x < 7; x++)
		{
			stacks[x][y] = new Card(0, 0);
		}
	}

	for(int y = 0; y < 13; y++)
	{
		for(int x = 0; x < 7; x++)
		{
			visible_cards[x][y] = false;
		}
	}

	for(int x = 0; x < 7; x++)
	{
		for(int y = 0; y < x + 1; y++)
		{
			stacks[x][y] = new Card((rand() % 5) - 1, rand() % 15);
		}

		visible_cards[x][0] = true;
	}

	for(int i = 0; i < 24; i++)
	{
		pile[i] = new Card((rand() % 5) - 1, rand() % 15);
	}

	DisplayBoard(stacks, visible_cards, pile);
}

void Board::DisplayBoard(Card* stacks[7][13], bool visible_cards[7][13], Card* pile[24])
{
	std::stringstream display_string;

	//Display seven header cards
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if(visible_cards[j][0] == true)
			{
				switch(i)
				{
					case 0:
						display_string << " --------- ";
						break;

					case 1:
						display_string << "|" << ranks[stacks[j][0]->GetRank()] << " " << suits[stacks[j][0]->GetSuit()] << "     ";

						if(stacks[j][0]->GetRank() != 10)
							display_string << " |";
						else
							display_string << "|";

						break;
					
					case 4:
						display_string << "|   CBE   |";
						break;

					case 7:
						if(stacks[j][0]->GetRank() != 10)
							display_string << "| ";
						else
							display_string << "|";

						display_string << "     " << suits[stacks[j][0]->GetSuit()] << " " << ranks[stacks[j][0]->GetRank()] << "|";

						break;

					case 8:
						display_string << " --------- ";
						break;
					
					default:
						display_string << "|         |";
						break;
				}
			}
			else
			{
				display_string << "         ";
			}
		
			display_string << " ";
		}

		display_string << "\n";
	}

	//Display how many under cards there are
	for(int i = 0; i < 7; i++)
	{
		display_string << " ----" << std::hex << CountUnderCards(stacks, i) << "---- ";

		display_string << " ";
	}		

	//Display under cards if visible
	/*
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			switch(i)
			{
				case 0:
					display_string << " --------- ";
					break;

				case 1:
					display_string << "|" << ranks[stacks[j][0]->GetRank()] << " " << suits[stacks[j][0]->GetSuit()] << "      |";
					break;
				
				case 4:
					display_string << "|   CBE   |";
					break;

				case 7:
					display_string << "|      " << suits[stacks[j][0]->GetSuit()] << " " << ranks[stacks[j][0]->GetRank()] << "|";
					break;

				case 8:
					display_string << " --------- ";
					break;
				
				default:
					display_string << "|         |";
					break;
			}

			display_string << " ";
		}

		display_string << "\n";
	}
	*/
	
	std::cout << display_string.str() << std::endl;
}

int Board::CountUnderCards(Card* stacks[7][13], int column)
{
	int numUnder = 0;

	for(int i = 1; i < 13; i++)
	{
		if(stacks[column][i]->GetRank() != 0)
		{
			numUnder++;
		}
	}

	return numUnder;
}
