#pragma once
#include "Queue.h"
class GC
{
public:
	GC();
	~GC();
	void add(void* item);
	void clear();
private:
	Queue<void*> _queue;
};

