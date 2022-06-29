#include <iostream>
#include "Farm.h"
#include "Store.h"
#include "Feed.h"
#include "Pig.h"
#include "PigFeed.h"
#include "Cow.h"
#include "CowFeed.h"
#include "Chicken.h"
#include "ChickenFeed.h"

int main()
{
	//Задаем количество корма для животных
	PigFeed pigFeed;
	CowFeed cowFeed;
	ChickenFeed chickenFeed;
	FeedBox pigFeedBox(&pigFeed, 200);
	FeedBox cowFeedBox(&cowFeed, 200);
	FeedBox chickenFeedBox(&chickenFeed, 200);

	//Добавляем в склад все 
	Store store({ &pigFeedBox, &cowFeedBox, &chickenFeedBox });

	//Создаем живоотных(можно улучшить создавать рандомно)
	Pig pig1(20, &pigFeed);
	Pig pig2(20, &pigFeed);

	Cow cow1(35, &cowFeed);
	Cow cow2(35, &cowFeed);
	Cow cow3(35, &cowFeed);

	Chicken chicken1(10, &chickenFeed);
	Chicken chicken2(10, &chickenFeed);
	Chicken chicken3(10, &chickenFeed);
	Chicken chicken4(10, &chickenFeed);

	//Создаем ферму и помещаем туда животных
	Farm farm;
	farm.AddStore(&store);
	farm.AddAnimal(&pig1);
	farm.AddAnimal(&pig2);
	farm.AddAnimal(&cow1);
	farm.AddAnimal(&cow2);
	farm.AddAnimal(&cow3);
	farm.AddAnimal(&chicken1);
	farm.AddAnimal(&chicken2);
	farm.AddAnimal(&chicken3);
	farm.AddAnimal(&chicken4);

	//Кормим
	farm.FeedAllAnimal();

	//Остатки
	store.PrintListFeeds();
	
	return 0;

}
