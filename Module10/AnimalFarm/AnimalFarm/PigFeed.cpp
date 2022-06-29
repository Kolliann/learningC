#include "PigFeed.h"

PigFeed::PigFeed()
{
	_typeFeed = "Pig_feed";
}

PigFeed::~PigFeed(){}

Feed* PigFeed::GetFeedType()
{
	return this;
}

const std::string& PigFeed::GetFeedTypeToString() const
{
	return this->_typeFeed;
}
