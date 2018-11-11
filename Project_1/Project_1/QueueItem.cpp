// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "QueueItem.h"

QueueItem::ItemKind QueueItem::getKind()
{
		return _kind;
}

QueueItem::QueueItem()
{
}

QueueItem::~QueueItem()
{
}
