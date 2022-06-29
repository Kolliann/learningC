#include "Feed.h"

Feed::~Feed(){}

Feed* Feed::GetFeedType(){ return this; }

const std::string& Feed::GetFeedTypeToString() const
{
	return this->_typeFeed;
}
