#pragma once
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
	Operation(const QJsonObject& object);
	virtual ~Operation();
	Action getAction() const;
	int getDuration() const;
	void setAction(const Action action);
	void setDuration(const int duration);
	bool operator==(const Operation& operation) const;
	virtual void print(std::ostream& out) const override;
	friend std::ostream& operator<<(std::ostream& out, const Operation::Action  &value) {
		switch (value)
		{
		case Operation::Action::NONE:
			return out << "nothing";
		case Operation::Action::CHOP:
			return out << "chop";
		case Operation::Action::PACK:
			return out << "pack";
		case Operation::Action::FRY:
			return out << "fry";
		case Operation::Action::PUT:
			return out << "put";
		case Operation::Action::BOIL:
			return out << "boil";
		default:
			return out << "unknown";
			break;
		}
	}
	friend std::ostream& operator<<(std::ostream& out, const Operation  &value) {
		value.print(out);
		return out;
	}
	virtual QJsonObject serialize() override;
private:
	virtual void deserialize(const QJsonObject& object) override;
	Action _action;
	int _duration;

	// Унаследовано через QueueItem
	virtual QString toString() const override;
};

