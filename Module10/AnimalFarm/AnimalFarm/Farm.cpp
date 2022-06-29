#include <iostream>
#include "Farm.h"

Farm::~Farm(){}

void Farm::AddAnimal(Animal* animal)
{
	_animals.push_back(animal);
}

void Farm::FeedAllAnimal()
{
	std::cout << "Start step feed animal->\n";

	std::vector<FeedBox*> feedBoxs = _store->GetFeeds();
	
		for (FeedBox* feedBox : feedBoxs) {
			for (Animal* animal : _animals) {

				if (animal->CanEatThisFeed(feedBox->feed))
				{
					int supplies = _store->GetFoodSupplies(feedBox->feed, animal->GetHungryLevel());
					
					animal->Eat(supplies);

				}
			}
		}
	std::cout << "Stop step feed animal-> \n";
}

void Farm::AddStore(Store* store)
{
	_store = store;
}

const std::vector<Animal*>& Farm::GetAnimals() const
{
	return _animals;
}