#pragma once
#include "Animal.h"

class Pig : virtual public Animal
{
public:
	Pig( const int hungerLevel );
	Pig( const int hungerLevel, Feed* feed );
	~Pig();
	void Eat( int ) const override;
	Feed* GetFeedType() const override;
	bool CanEatThisFeed(Feed* feed ) override;
	int GetHungryLevel() const override;
};

