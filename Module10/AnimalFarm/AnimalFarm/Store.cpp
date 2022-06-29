#include <iostream>
#include "Store.h"

Store::Store(std::vector<FeedBox*> feedBox): _feedBoxs(feedBox)
{
	//_feedBoxs.push_back(&_feedBox);
	//_feedBoxs = *_feedBoxsss;
}

Store::~Store(){}

void Store::AddFeedType(Feed* feed)
{
	_feeds.push_back(feed);
}

FeedBox::FeedBox(Feed* feed, int count) : feed(feed), count(count){}

std::vector<FeedBox*>& Store::GetFeeds()
{
	return _feedBoxs;
}

int Store::GetFoodSupplies(Feed* feed, int count)
{
	int portion = count;
	for (auto a : _feedBoxs) {

		if (feed->GetFeedType() == a->feed) 
		{
			if (a->count >= portion) {
				int tmpValue = a->count;
				a->count -= portion;
				return tmpValue;
			}
			else
			{
				int tmpValue = a->count;
				a->count = 0;
				return tmpValue;
			}
		}
	}
	return 0;
}

void Store::PrintListFeeds()
{
	for (auto& feedBox : _feedBoxs)
	{
		std::cout << feedBox->feed->GetFeedTypeToString() << " " << feedBox->count  << "\n";
	}
}
