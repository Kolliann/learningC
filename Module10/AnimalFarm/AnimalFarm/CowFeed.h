#pragma once
#include "Feed.h"
class CowFeed : virtual public Feed
{
public:
	CowFeed();
	~CowFeed();
	Feed* GetFeedType() override;
	const std::string& GetFeedTypeToString() const override;

};
