#include "Deck.h"

Deck::Deck() : m_card{ 0 }
{
	m_deck = new Card * [ConstansBlackJack::maxCountCards];

	int card{ 0 };

	for (int suit = 0; suit < Card::MAX_SUIT; ++suit)
		for (int rank = 0; rank < Card::MAX_RANK; ++rank)
			m_deck[card++] = new Card{ static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank) };

	shuffleDeck();
}

Deck::~Deck() { delete[] m_deck; }

void Deck::shuffleDeck()
{
	for (int card = 0; card < ConstansBlackJack::maxCountCards; ++card)
		std::swap(m_deck[card], m_deck[RandomNumber::getRandomNumber(0, ConstansBlackJack::maxCountCards - 1)]);
}

Card& Deck::showCard() const { return *m_deck[m_card]; }
Card& Deck::getCard()        { return *m_deck[m_card++]; }