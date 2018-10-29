#pragma once
#include <QFile>
#include <QJsonObject>
#include <QJsonArray.h>
#include <QJsonDocument>
#include"Ingredient.h"

class Queue
{
public:
	struct ListItem {
		Ingredient obj;
		ListItem *next;
		ListItem(const Ingredient &ingredient);
	};
	class Iterator {
	public:
		Iterator(ListItem* ptr) {
			_ptr = ptr;
		}
		~Iterator(){}
		Iterator operator++(int) {
			Iterator i = *this;
			_ptr = _ptr->next;
			return i;
		}
		Iterator& operator++() {
			_ptr = _ptr->next;
			return *this;
		}
		Ingredient& operator*() const{
			return _ptr->obj;
		}
		bool operator==(const Iterator& rhs) const{
			return _ptr == rhs._ptr;
		}
		bool operator!=(const Iterator& rhs) const{
			return _ptr != rhs._ptr;
		}
	private:
		ListItem* _ptr;
	};
	Queue();
	Queue(const Queue &queue);
	~Queue();

	void push(Ingredient &ingredient);
	Ingredient& pop();

	Iterator begin() const;
	Iterator end() const;

	void clear();
	int getCount() const;

	void dump(const QString filepath) const;
	static Queue load(const QString filepath);

	bool equal(const Queue &queue) const;
private:

	ListItem *_head, *_tail;
	int _count;
};

void printQueue(Queue queue);