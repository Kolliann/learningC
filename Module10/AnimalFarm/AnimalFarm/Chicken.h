#pragma once
#include "Animal.h"
class Chicken : virtual public Animal
{
public:
	Chicken(const int hungerLevel);
	Chicken(const int hungerLevel, Feed* feed);
	~Chicken();
	void Eat(int) const override;
	Feed* GetFeedType() const override;
	bool CanEatThisFeed(Feed* feed) override;
	int GetHungryLevel() const override;
};
