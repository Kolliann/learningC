#pragma once
#include <vector>
#include "Feed.h"

struct FeedBox
{
	FeedBox() = default;
	FeedBox(Feed* feed, int count);
	Feed* feed;
	int count;
};

class Store
{	
	public:
		Store(std::vector<FeedBox*>);
		~Store();
		void AddFeedType(Feed* feed);
		std::vector<FeedBox*>& GetFeeds();
		int GetFoodSupplies(Feed* feed, int count);
		void PrintListFeeds();
	
	private:
		FeedBox _feedBox;
		std::vector<Feed*> _feeds;
		std::vector<FeedBox*> _feedBoxs;

		std::vector<FeedBox> _feedBoxsss;
};