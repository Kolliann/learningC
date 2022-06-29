#include "Animal.h"
#include <iostream>
Animal::Animal(const int hungerLevel) : _hungerLevel(hungerLevel)
{
	_feed = nullptr;
}
Animal::Animal(const int hungerLevel, Feed* feed) : _hungerLevel(hungerLevel), _feed(feed){}

Animal::~Animal(){}

Feed* Animal::GetFeedType() const
{
	 return _feed;
}

bool Animal::CanEatThisFeed(Feed* feed)
{
	 auto m = dynamic_cast<Feed*>(feed);
	 if (nullptr != m)
		 return true;
	 else
		 return false;
}

int Animal::GetHungryLevel() const
{
	 return _hungerLevel;
}

void Animal::Eat(int amountOfFeed) const
{
	if (amountOfFeed >= _hungerLevel)
		std::cout << "num num" << "\n";
	else
		std::cout << "PPP-pp" << "\n";
}