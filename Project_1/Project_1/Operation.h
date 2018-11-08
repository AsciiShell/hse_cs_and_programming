#pragma once
#include <stdio.h>
#include <iostream>
#include <QString>
#include "QueueItem.h"
class Operation : public QueueItem
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
	Operation(const QJsonObject object);
	~Operation();
	Action getAction() const;
	int getDuration() const;
	void setAction(const Action action);
	void setDuration(const int duration);
	bool operator==(const Operation operation) const;
	// Унаследовано через QueueItem
	virtual QJsonObject serialize() override;
private:
	virtual void deserialize(const QJsonObject object) override;
	Action _action;
	int _duration;
};

