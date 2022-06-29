#pragma once
#include "Feed.h"

class PigFeed : virtual public Feed
{
public:
	PigFeed();
	~PigFeed();
	Feed* GetFeedType() override;
	const std::string& GetFeedTypeToString() const override;

};

