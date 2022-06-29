#pragma once
#include "Animal.h"
class Cow : virtual public Animal
{
public:
	Cow(const int hungerLevel);
	Cow(const int hungerLevel, Feed* feed);
	~Cow();
	void Eat(int) const override;
	Feed* GetFeedType() const override;
	bool CanEatThisFeed(Feed* feed) override;
	int GetHungryLevel() const override;
};
