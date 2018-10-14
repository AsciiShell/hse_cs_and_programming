#pragma once
#include <QFile>
#include <QJsonObject>
#include <QJsonArray.h>
#include <QJsonDocument>
#include"Ingredient.h"
class Queue
{
public:
	typedef Ingredient* iterator;
	Queue();
	Queue(const Queue &queue);
	~Queue();

	void push(Ingredient &ingredient);
	Ingredient& pop();

	iterator begin() const;
	iterator end() const;

	void clear();
	int getCount() const;

	void dump(const QString filepath) const;
	static Queue load(const QString filepath);

	bool equal(const Queue &queue) const;
private:
	Ingredient *_objects, *_head, *_tail;
	int _count, _allocated;
	static const size_t ALLOCATE_SIZE = 4;
	void grow(size_t size = ALLOCATE_SIZE);
};

void printQueue(Queue queue);