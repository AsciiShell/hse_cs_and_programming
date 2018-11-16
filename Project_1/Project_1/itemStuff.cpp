// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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