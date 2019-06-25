#include "RandomNumber.h"

int RandomNumber::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(fraction * rand() * (max - min + 1) + min);
}