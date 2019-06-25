#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "Constans.h"
#include "RandomNumber.h"

class Deck
{
public:

	Deck();
	~Deck();

	void shuffleDeck();
	Card& showCard() const;
	Card& getCard();

private:
	Card** m_deck;
	int m_card;
};
#endif // !DECK_H
