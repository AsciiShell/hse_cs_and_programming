#pragma once
#include <QFile>
#include <QJsonObject>
#include <QJsonArray.h>
#include <QJsonDocument>
#include "itemFactory.h"

template <class T>
class Queue
{
public:
	struct ListItem {
		T obj;
		ListItem *next;
		ListItem(const T & object)
		{
			obj = object;
			this->next = nullptr;
		}
	};
	class Iterator {
	public:
		Iterator(ListItem* ptr) {
			_ptr = ptr;
		}
		~Iterator() {}
		Iterator operator++(int) {
			Iterator i = *this;
			_ptr = _ptr->next;
			return i;
		}
		Iterator& operator++() {
			_ptr = _ptr->next;
			return *this;
		}
		T& operator*() const {
			return _ptr->obj;
		}
		bool operator==(const Iterator& rhs) const {
			return _ptr == rhs._ptr;
		}
		bool operator!=(const Iterator& rhs) const {
			return !(_ptr == rhs._ptr);
		}
	private:
		ListItem* _ptr;
	};
	Queue()
	{
		_tail = _head = nullptr;
		_count = 0;
	}
	Queue(const Queue&queue)
	{
		copy(queue);
	}
	Queue<T>& operator=(const Queue<T> &queue)
	{
		copy(queue);
		return *this;
	}
	~Queue()
	{
		clear();
	}

	void push(T & object)
	{
		if (_tail == nullptr) {
			_tail = _head = new ListItem(object);
			_count = 1;
		}
		else {
			auto tmp = new ListItem(object);
			_head->next = tmp;
			_head = tmp;
			_count += 1;
		}
	}
	T pop()
	{
		if (_count > 0) {
			T result = _tail->obj;
			ListItem* old_tail = _tail;
			_tail = _tail->next;
			delete old_tail;
			_count -= 1;
			return result;
		}
		else
			throw std::exception("Queue is empty");
	}

	T at(int index) {
		if (index >= _count)
			throw std::exception("Index out of range");
		int i = 0;
		ListItem* ptr = _tail;
		while (ptr != nullptr && i++ < index)
		{
			ptr = ptr->next;
		}
		return ptr->obj;
	}

	Iterator begin() const
	{
		return Iterator(_tail);
	}
	Iterator end() const
	{
		return Iterator(nullptr);
	}

	void clear()
	{
		while (_tail != nullptr)
		{
			auto old_tail = _tail;
			_tail = _tail->next;
			delete old_tail;
		}
		_tail = _head = nullptr;
		_count = 0;
	}
	int getCount() const
	{
		return _count;
	}

	void dump(const QString& filepath) const
	{
		QJsonArray jsonArray;
		for (auto i = _tail; i != nullptr; i = i->next)
		{
			T item = i->obj;
			jsonArray.append(item->serialize());
		}
		QJsonDocument jsonDoc(jsonArray);
		QFile file(filepath);
		file.open(QIODevice::WriteOnly);
		file.write(jsonDoc.toJson());
		file.close();
	}
	void load(const QString& filepath)
	{
		clear();
		QFile file(filepath);
		file.open(QIODevice::ReadOnly);
		QJsonArray jsonArray = QJsonDocument::fromJson(file.readAll()).array();
		for (auto i = 0; i < jsonArray.count(); i++) {
			T item = itemFactory<T>(jsonArray.at(i).toObject());
			push(item);
		}
	}

	bool equal(const Queue &queue) const
	{
		bool result = queue.getCount() == _count;
		for (auto i = _tail, j = queue._tail; i != nullptr && j != nullptr && result; i = i->next, j = j->next)
			result = i->obj == j->obj;
		return result;
	}
private:
	void copy(const Queue&queue) {
		clear();
		for (auto i = queue._tail; i != nullptr; i = i->next) {
			push(T(i->obj));
		}
	}
	ListItem *_head, *_tail;
	int _count;
};

template <class T>
void printQueue(Queue<T> queue)
{
	auto i = queue.begin();
	int number = 1;
	for (; i != queue.end(); i++, number++) {
		std::cout << number << ": ";
		T obj = *i;
		obj->print(std::cout);
		std::cout << std::endl;

	}
	std::cout << std::endl;
}