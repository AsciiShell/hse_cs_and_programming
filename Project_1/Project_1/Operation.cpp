// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "Operation.h"

Operation::Operation()
{
	_action = NONE;
	_duration = 0;
	_kind = ITEM_OPERATION;
}

Operation::Operation(const Action action, const int duration)
{
	_action = action;
	_duration = duration >= 0 ? duration : 0;
	_kind = ITEM_OPERATION;
}

Operation::Operation(const Operation & operation)
{
	_action = operation.getAction();
	_duration = operation.getDuration();
	_kind = ITEM_OPERATION;
}

Operation::Operation(const QJsonObject object) {
	_kind = ITEM_OPERATION;
	deserialize(object);
}

Operation::~Operation()
{
}

Operation::Action Operation::getAction() const
{
	return _action;
}

int Operation::getDuration() const
{
	return _duration;
}

void Operation::setAction(const Action action)
{
	_action = action;
}

void Operation::setDuration(const int duration)
{
	if (duration >= 0)
		_duration = duration;
}

bool Operation::operator==(const Operation& operation) const
{
	return _duration == operation._duration && _action == operation._action;
}

void Operation::print(std::ostream & out) const
{
	out << _action << " for " << _duration << " seconds";
}

QJsonObject Operation::serialize()
{
	QJsonObject jsonObject;
	jsonObject["action"] = _action;
	jsonObject["duration"] = _duration;
	jsonObject["kind"] = ITEM_OPERATION;
	return jsonObject;
}

void Operation::deserialize(const QJsonObject object)
{
	_action = static_cast<Operation::Action>(object["action"].toInt());
	_duration = object["duration"].toInt();
	if (_duration < 0)
		_duration = 0;
}
