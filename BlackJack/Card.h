#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card
{
public:

	enum Suit
	{
		PIKI,
		TREFU,
		CHERVU,
		BYBNU,
		MAX_SUIT
	};

	enum Rank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_VALET,
		RANK_QUEEN,
		RANK_KOROL,
		RANK_TYZ,
		MAX_RANK
	};

	Card(Suit = MAX_SUIT, Rank = MAX_RANK);

	void printCard() const;
	int getCardValue() const;

private:
	Suit m_suit;
	Rank m_rank;
};
#endif // !CARD_H
