#include <iostream>
#include "Chicken.h"
#include "ChickenFeed.h"

Chicken::Chicken(const int hungerLevel) : Animal(hungerLevel) {}

Chicken::Chicken(const int hungerLevel, Feed* feed) : Animal(hungerLevel, feed) {}

Chicken::~Chicken() {}

void Chicken::Eat(int amountOfFeed) const
{
	if (amountOfFeed >= _hungerLevel)
		std::cout << "co co coo" << "\n";
	else
		std::cout << "chicken PPP-pp" << "\n";
}

Feed* Chicken::GetFeedType() const {
	return _feed;
}

bool Chicken::CanEatThisFeed(Feed* feed)
{
	auto catsFeedType = dynamic_cast<ChickenFeed*>(feed);
	if (nullptr != catsFeedType)
		return true;
	else
		return false;
}

int Chicken::GetHungryLevel() const
{
	return _hungerLevel;
}
