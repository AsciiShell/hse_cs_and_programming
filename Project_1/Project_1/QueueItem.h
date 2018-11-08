#pragma once
#include <QJsonObject>

class QueueItem
{
public:
	enum ItemKind { ITEM_INGREDIENT, ITEM_OPERATION };
	ItemKind getKind();
	QueueItem();
	virtual ~QueueItem();
	virtual QJsonObject serialize() = 0;
protected:
	virtual void deserialize(const QJsonObject object) = 0;
	ItemKind _kind;
};

