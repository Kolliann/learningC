#pragma once
#include "Feed.h"
class ChickenFeed : virtual public Feed
{
public:
	ChickenFeed();
	~ChickenFeed();
	Feed* GetFeedType() override;
	const std::string& GetFeedTypeToString() const override;

};
