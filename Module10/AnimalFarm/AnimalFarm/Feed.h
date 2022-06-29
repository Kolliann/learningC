#pragma once
#include <string>
class Feed
{

public:

	Feed() = default;
	virtual ~Feed();
	virtual Feed* GetFeedType();
	virtual const std::string& GetFeedTypeToString() const;

protected:
	std::string _typeFeed = "Feed";
};

