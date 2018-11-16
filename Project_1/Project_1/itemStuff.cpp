#include "itemStuff.h"

bool itemEqual(const QueueItem* a, const QueueItem* b)
{
	bool result = a->getKind() == b->getKind();
	if (result)
	{
		if (a->getKind() == QueueItem::ITEM_INGREDIENT)
			result = *((Ingredient*)a) == *((Ingredient*)b);
		else
			result = *((Operation*)a) == *((Operation*)b);
	}
	return result;
}