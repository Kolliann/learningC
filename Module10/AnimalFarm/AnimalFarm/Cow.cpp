#include <iostream>
#include "Cow.h"
#include "CowFeed.h"

Cow::Cow(const int hungerLevel) : Animal(hungerLevel) {}

Cow::Cow(const int hungerLevel, Feed* feed) : Animal(hungerLevel, feed) {}

Cow::~Cow() {}

void Cow::Eat(int amountOfFeed) const
{
	if (amountOfFeed >= _hungerLevel)
		std::cout << "Moo moo" << "\n";
	else
		std::cout << "Cow PPP-pp" << "\n";
}

Feed* Cow::GetFeedType() const {
	return _feed;
}

bool Cow::CanEatThisFeed(Feed* feed)
{
	auto catsFeedType = dynamic_cast<CowFeed*>(feed);
	if (nullptr != catsFeedType)
		return true;
	else
		return false;
}

int Cow::GetHungryLevel() const
{
	return _hungerLevel;
}
