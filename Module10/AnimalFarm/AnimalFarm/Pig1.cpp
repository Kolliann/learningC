#include <iostream>
#include "Pig.h"
#include "PigFeed.h"

Pig::Pig(const int hungerLevel) : Animal(hungerLevel){}

Pig::Pig(const int hungerLevel, Feed* food) : Animal(hungerLevel,food){}

Pig::~Pig(){}

void Pig::Eat( int amountOfFeed ) const
{
	if(amountOfFeed >= _hungerLevel )
		std::cout << "xru xru" << "\n";
	else
		std::cout << "pig PPP-pp"  << "\n";
}

Feed* Pig::GetFoodType() const {
	return _food; 
}

bool Pig::CanEatThisFood(Feed* food)
{
	auto catsFoodType = dynamic_cast<PigFeed*>(food);
	if ( nullptr != catsFoodType )
		return true;
	else
		return false;
}

int Pig::GetHungryLevel() const
{
	return _hungerLevel;
}
