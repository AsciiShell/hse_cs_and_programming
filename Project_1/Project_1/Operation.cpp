#include "Operation.h"

Operation::Operation()
{
	_action = NONE;
	_duration = 0;
}

Operation::Operation(const Action action, const int duration)
{
	_action = action;
	_duration = duration >= 0 ? duration : 0;
}

Operation::Operation(const Operation & operation)
{
	_action = operation.getAction();
	_duration = operation.getDuration();
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

bool Operation::operator==(const Operation operation) const
{
	return _duration == operation._duration && _action == operation._action;
}
