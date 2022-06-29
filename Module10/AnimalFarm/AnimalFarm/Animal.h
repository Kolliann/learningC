#pragma once
#include "Feed.h"	
class Animal
{
public:
	Animal() = default;
	Animal(const int hungerLevel);
	Animal(const int hungerLevel, Feed* feed);
	virtual ~Animal();
	virtual void Eat(int) const;
	virtual Feed* GetFeedType() const;
	virtual bool CanEatThisFeed(Feed* feed);
	virtual int GetHungryLevel() const;

protected:
	int _hungerLevel;
	Feed* _feed = nullptr;
};

