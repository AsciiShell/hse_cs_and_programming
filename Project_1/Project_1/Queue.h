#pragma once
#include <QFile>
#include <QJsonObject>
#include <QJsonArray.h>
#include <QJsonDocument>

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
			return _ptr != rhs._ptr;
		}
	private:
		ListItem* _ptr;
	};
	Queue()
	{
		_tail = _head = nullptr;
		_count = 0;
	}
	Queue(const Queue &queue)
	{
		_tail = _head = nullptr;
		_count = 0;
		for (auto i = queue._tail; i != nullptr; i = i->next) {
			push(T(i->obj));
		}
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
		_count = 0;
	}
	int getCount() const
	{
		return _count;
	}

	void dump(const QString filepath) const
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
	static Queue load(const QString filepath)
	{
		QFile file(filepath);
		file.open(QIODevice::ReadOnly);
		QJsonArray jsonArray = QJsonDocument::fromJson(file.readAll()).array();
		Queue queue;
		for (auto i = 0; i < jsonArray.count(); i++) {
			queue.push(T(jsonArray.at(i).toObject()));
		}
		return queue;
	}

	bool equal(const Queue &queue) const
	{
		bool result = queue.getCount() == _count;
		for (auto i = _tail, j = queue._tail; i != nullptr && j != nullptr && result; i = i->next, j = j->next)
			result = i->obj == j->obj;
		return result;
	}
private:

	ListItem *_head, *_tail;
	int _count;
};

template <class T>
void printQueue(Queue<T> queue)
{
	auto i = queue.begin();
	int number = 1;
	for (; i != queue.end(); i++, number++) {
		std::cout << number << ": " << *i << std::endl;

	}
}