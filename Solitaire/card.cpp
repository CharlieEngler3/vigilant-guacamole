#include "common.h"

const std::string suits[4] = { "♡", "♧", "◇", "♤" };
const std::string suit_names[4] = { "Hearts", "Clubs", "Diamonds", "Spades" };

const std::string ranks[15] = { "R", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
const std::string rank_names[15] = { "Joker", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };

const int card_width = 11;
const int card_height = 7;

Card::Card(int suit, int rank)
{
	this->suit = suit;
	this->rank = rank;

//	std::cout << "Card of suit ˹" << suit_names[suit] << " " << suits[suit] << "˼ and rank ˹" << rank_names[rank] << " " << ranks[rank] << "˼ created." << std::endl; 
//	DisplayCard(suit, rank);
}

void Card::DisplayCard(int suit, int rank)
{
	std::stringstream display_string;

	display_string << " --------- " << "\n";

	display_string << "|" << ranks[rank] << " " << suits[suit] << "      |" << "\n";

	display_string << "|         |" << "\n";
	display_string << "|         |" << "\n";
	display_string << "|   CBE   |" << "\n";
	display_string << "|         |" << "\n";
	display_string << "|         |" << "\n";

	display_string << "|      " << suits[suit] << " " << ranks[rank] << "|" << "\n";

	display_string << " --------- ";

	std::cout << display_string.str() << std::endl;
}

int Card::GetSuit()
{
	return this->suit;
}

int Card::GetRank()
{
	return this->rank;
}
