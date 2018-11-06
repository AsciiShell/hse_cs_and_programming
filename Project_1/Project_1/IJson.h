#pragma once
#include <QJsonObject>

class IJson
{
public:
	virtual QJsonObject serialize() = 0;
	virtual void deserialize(const QJsonObject object) = 0;
};
