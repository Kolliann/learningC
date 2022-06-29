#include "ChickenFeed.h"

ChickenFeed::ChickenFeed()
{
	_typeFeed = "Chicken_feed";
}

ChickenFeed::~ChickenFeed() {}

Feed* ChickenFeed::GetFeedType()
{
	return this;
}

const std::string& ChickenFeed::GetFeedTypeToString() const
{
	return this->_typeFeed;
}
