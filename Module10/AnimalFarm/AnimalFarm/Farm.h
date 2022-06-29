#pragma once
#include <vector>
#include "Animal.h"
#include "Store.h"

class Farm
{
public:
	~Farm();

	void AddAnimal(Animal* animal);

	void FeedAllAnimal();

	void AddStore(Store* store);

	const std::vector<Animal*>& GetAnimals() const;

private:
	std::vector<Animal*> _animals;
	Store* _store;
};

