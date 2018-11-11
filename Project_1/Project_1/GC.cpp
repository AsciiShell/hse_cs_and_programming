// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "GC.h"



GC::GC()
{
}


GC::~GC()
{
	clear();
}

void GC::add(void * item)
{
	_queue.push(item);
}

void GC::clear()
{
	while (_queue.getCount() != 0)
	{
		void* item = _queue.pop();
		delete item;
	}
}
