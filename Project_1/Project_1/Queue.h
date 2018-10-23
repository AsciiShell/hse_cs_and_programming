#pragma once
#include <QFile>
#include <QJsonObject>
#include <QJsonArray.h>
#include <QJsonDocument>
#include"Ingredient.h"
class Queue
{
public:
	//typedef Ingredient* iterator;
	Queue();
	Queue(const Queue &queue);
	~Queue();

	void push(Ingredient &ingredient);
	Ingredient& pop();

	//iterator begin() const;
	//iterator end() const;

	void clear();
	int getCount() const;

	void dump(const QString filepath) const;
	static Queue load(const QString filepath);

	bool equal(const Queue &queue) const;
private:
	struct ListItem {
		Ingredient obj;
		ListItem *next;
		ListItem(const Ingredient &ingredient);
	};
	ListItem *_head, *_tail;
	int _count;
};

void printQueue(Queue queue);