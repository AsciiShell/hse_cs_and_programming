#pragma once
#include "Queue.h"
template <class T>
class GC
{
public:
	GC() {}
	~GC()
	{
		clear();
	}
	void add(T* item)
	{
		_queue.push(item);
	}
	void clear()
	{
		while (_queue.getCount() != 0)
		{
			T* item = _queue.pop();
			delete item;
		}
	}
private:
	Queue<T*> _queue;
};

