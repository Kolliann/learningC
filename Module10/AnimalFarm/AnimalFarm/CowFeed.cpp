#include "CowFeed.h"

CowFeed::CowFeed()
{
	_typeFeed = "Cow_feed";
}

CowFeed::~CowFeed() {}

Feed* CowFeed::GetFeedType()
{
	return this;
}

const std::string& CowFeed::GetFeedTypeToString() const
{
	return this->_typeFeed;
}
