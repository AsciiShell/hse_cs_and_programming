#pragma once
#include "Ingredient.h"
#include "Operation.h"
#include "QueueItem.h"
#include "QJsonObject.h"

template <class T>
T itemFactory(const QJsonObject &object) {
	QueueItem::ItemKind kind = static_cast<QueueItem::ItemKind>(object["kind"].toInt());
	switch (kind)
	{
	case QueueItem::ITEM_INGREDIENT:
		return new Ingredient(object);
	case QueueItem::ITEM_OPERATION:
		return new Operation(object);
	default:
		throw std::exception("Unknown QueueItem type.\n");
	}
}