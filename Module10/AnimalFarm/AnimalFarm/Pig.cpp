#include <iostream>
#include "Pig.h"
#include "PigFeed.h"

Pig::Pig( const int hungerLevel ) : Animal( hungerLevel ){}

Pig::Pig( const int hungerLevel, Feed* feed ) : Animal( hungerLevel, feed ){}

Pig::~Pig(){}

void Pig::Eat( int amountOfFeed ) const
{
	if(amountOfFeed >= _hungerLevel )
		std::cout << "xru xru" << "\n";
	else
		std::cout << "pig PPP-pp"  << "\n";
}

Feed* Pig::GetFeedType() const {
	return _feed; 
}

bool Pig::CanEatThisFeed(Feed* feed)
{
	auto catsFeedType = dynamic_cast<PigFeed*>(feed);
	if ( nullptr != catsFeedType )
		return true;
	else
		return false;
}

int Pig::GetHungryLevel() const
{
	return _hungerLevel;
}
