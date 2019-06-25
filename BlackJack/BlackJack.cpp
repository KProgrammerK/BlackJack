#include "Deck.h"
#include "ADD.h"
#include "Constans.h"

#include <string>

inline std::string getAnswer()
{
	std::string answer;
	do
	{
		std::cout << "Your action (take,stand):";
		getline(std::cin, answer);
	} while (answer != "take" && answer != "stand");
	return answer;
}

inline bool checkTyz(const Card& card) 
{
	return card.getCardValue() == 11 ? true : false;
}

inline void gotCard(int& result, int& tyzCount, Deck* deck)
{
	if (checkTyz(deck->showCard()))
		++tyzCount;
	result += deck->getCard().getCardValue();
}

inline void changeValueTyz(int& result, int& tyzCount)
{
	while (tyzCount > 0)
	{
		result -= 10;
		--tyzCount;
	}
}

ResultGame playBlackJack(Deck* deck)
{
	//------------THIS IS START-----------------------
	std::cout << "It's BlackJack.\n";
	
	int playerResult{ 0 };
	int playerTyz{ 0 };

	int dealerResult{ 0 };
	int dealerTyz{ 0 };

	std::cout << "Dealer got a card.\n";
	gotCard(dealerResult, dealerTyz, deck);

	std::cout << "You got two card.\n";
	for (int card = 0; card < 2; ++card)
		gotCard(playerResult, playerTyz, deck);
	//-------------------------------------------------

	std::string answer;

	//Player action
	do
	{
		if (playerResult > ConstansBlackJack::maxResult)
		{
			if (playerTyz > 0)
			{
				std::cout << "Your result > 21 but you have tyz so tyz value = 1.\n";
				changeValueTyz(playerResult, playerTyz);
			}
			else
			{
				std::cout << "Player result = " << playerResult << '\n';
				return ResultGame::DEALER_WIN;
			}
		}

		std::cout << "Player result = " << playerResult << '\n';
		answer = getAnswer();
		if (answer == "stand")
			break;
		else
			gotCard(playerResult, playerTyz, deck);

	} while (answer == "take");

	//Dealer action
	while (dealerResult < 19)
	{
		std::cout << "Dealer result = " << dealerResult << '\n';
		gotCard(dealerResult, dealerTyz, deck);

		if (dealerResult > ConstansBlackJack::maxResult)
		{
			if (dealerTyz > 0)
			{
				std::cout << "Dealer result > 21 but he has tyz so tyz value = 1.\n";
				changeValueTyz(dealerResult, dealerTyz);
			}
			else
			{
				std::cout << "Dealer result = " << dealerResult << '\n';
				return ResultGame::PLAYER_WIN;
			}
		}
	}
	std::cout << "Dealer result = " << dealerResult << '\n';

	//------This is result of game----------
	if (dealerResult > playerResult)
		return ResultGame::DEALER_WIN;
	else if (playerResult > dealerResult)
		return ResultGame::PLAYER_WIN;
	else
		return ResultGame::DRAW;
	//---------------------------------------
}

int main()
{
	{
		srand(static_cast<unsigned int>(time(0)));
		rand();
	}

	auto deck = std::make_unique<Deck>();

	ResultGame resultGame = playBlackJack(deck.get());

	{
		switch (resultGame)
		{
		case ResultGame::PLAYER_WIN: std::cout << "You're win!\n"; break;
		case ResultGame::DEALER_WIN: std::cout << "Dealer win!\n"; break;
		case ResultGame::DRAW:       std::cout << "It's draw!\n";  break;
		}
	}

	return 0;
}