#pragma once
#include <stdio.h>
#include <iostream>
#include <QString>
class Operation
{
public:
	enum Action {
		NONE,
		CHOP,
		PACK,
		FRY,
		PUT,
		BOIL
	};
	Operation();
	Operation(const Action action, const int duration);
	Operation(const Operation &operation);
	~Operation();
	Action getAction() const;
	int getDuration() const;
	void setAction(const Action action);
	void setDuration(const int duration);
	bool operator==(const Operation operation) const;
private:
	Action _action;
	int _duration;
};

