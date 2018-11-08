#include "Queue.h"
#include <queue> 

Queue::Queue()
{
	_tail = _head = nullptr;
	_count = 0;
}

Queue::Queue(const Queue & queue)
{
	_tail = _head = nullptr;
	_count = 0;
	for (auto i = queue._tail; i != nullptr; i = i->next) {
		push(Ingredient(i->obj));
	}
}


Queue::~Queue()
{
	clear();
}

void Queue::push(Ingredient & ingredient)
{
	if (_tail == nullptr) {
		_tail = _head = new ListItem(ingredient);
		_count = 1;
	}
	else {
		auto tmp = new ListItem(ingredient);
		_head->next = tmp;
		_head = tmp;
		_count += 1;
	}
}

Ingredient Queue::pop()
{
	if (_count > 0) {
		auto result = _tail->obj;
		auto old_tail = _tail;
		_tail = _tail->next;
		delete old_tail;
		_count -= 1;
		return result;
	}
	else
		throw std::exception("Queue is empty");
}

Queue::Iterator Queue::begin() const
{
	return Iterator(_tail);
}

Queue::Iterator Queue::end() const
{
	return Iterator(nullptr);
}

void Queue::clear()
{
	while (_tail != nullptr)
	{
		auto old_tail = _tail;
		_tail = _tail->next;
		delete old_tail;
	}
	_count = 0;
}

int Queue::getCount() const
{
	return _count;
}


void Queue::dump(const QString filepath) const
{
	QJsonArray jsonArray;
	for (auto i = _tail; i != nullptr; i = i->next)
	{
		jsonArray.append(i->obj.serialize());
	}
	QJsonDocument jsonDoc(jsonArray);
	QFile file(filepath);
	file.open(QIODevice::WriteOnly);
	file.write(jsonDoc.toJson());
	file.close();
}

Queue Queue::load(const QString filepath)
{
	QFile file(filepath);
	file.open(QIODevice::ReadOnly);
	QJsonArray jsonArray = QJsonDocument::fromJson(file.readAll()).array();
	Queue queue;
	for (auto i = 0; i < jsonArray.count(); i++) {
		queue.push(Ingredient(jsonArray.at(i).toObject()));
	}
	return queue;
}

bool Queue::equal(const Queue &queue) const
{
	bool result = queue.getCount() == _count;
	for (auto i = _tail, j = queue._tail; i != nullptr && j != nullptr && result; i = i->next, j = j->next)
		result = i->obj == j->obj;
	return result;
}

void printQueue(Queue queue)
{
	auto i = queue.begin();
	int number = 1;
	for (; i != queue.end(); i++, number++) {
		std::cout << number << ": " << *i << std::endl;

	}
}

Queue::ListItem::ListItem(const Ingredient &ingredient)
{
	obj = ingredient;
	this->next = nullptr;
}
