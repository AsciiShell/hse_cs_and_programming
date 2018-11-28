#pragma once
#include <iostream>
#include "Hash.h"
template <class T>
class Counter
{
private:
	static const size_t DEFAULT_SIZE = 16;
	static const size_t GROW_RATE = 3;
	static const size_t MAX_COLLISION_COUNT = 3;

public:
	struct Item {
		T key;
		size_t count;
		Item(const T & k)
		{
			key = k;
			count = 0;
		}
	};
	Counter() {
		_size = DEFAULT_SIZE;
		_table = new Item*[_size];
		for (int i = 0; i < _size; i++)
			_table[i] = nullptr;
		_count = 0;
	}
	Counter(const Counter<T> & collection) {
		_size = 0;
		_count = 0;
		_table = nullptr;
	}
	void addKey(const T&key) {
		size_t index, steps;
		do {
			index = getHash(key);
			steps = 0;
			while (_table[index] != nullptr && steps < MAX_COLLISION_COUNT)
			{
				index = (index + 1) % _size;
				steps += 1;
			}
			if (steps == MAX_COLLISION_COUNT)
				grow();
		} while (steps == MAX_COLLISION_COUNT);
		_table[index] = new Item(key);
		_count += 1;
	}
	bool isIn(const T&key) const {
		size_t index = getHash(key);
		size_t steps = 0;
		while ((_table[index] == nullptr || _table[index]->key != key) && steps < MAX_COLLISION_COUNT)
		{
			index = (index + 1) % _size;
			steps += 1;
		}
		return steps == MAX_COLLISION_COUNT;
	}
	void remove(const T&key) {
		size_t index = getHash(key);
		size_t steps = 0;
		while ((_table[index] == nullptr || _table[index]->key != key) && steps < MAX_COLLISION_COUNT)
		{
			index = (index + 1) % _size;
			steps += 1;
		}
		if (steps == MAX_COLLISION_COUNT)
			throw std::exception("Key not found");
		else {
			delete _table[index];
			_count -= 1;
		}
	}
	void clear() {
		for (size_t i = 0; i < _size; i++)
			delete _table[i];
		_count = 0;
	}
	size_t getCount() const {
		return _count;
	}
	class Iterator {
	public:
		Iterator(Item* ptr) {
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
		int getValue() {
			return 0;
		}
		T getKey() {
			return NULL;
		}
		bool operator==(const Iterator& rhs) const {
			return _ptr == rhs._ptr;
		}
		bool operator!=(const Iterator& rhs) const {
			return !(_ptr == rhs._ptr);
		}
	private:
		Item* _ptr;
	};
	Iterator begin() const
	{
		return Iterator();
	}
	Iterator end() const
	{
		return Iterator(nullptr);
	}

	bool operator==(const Counter<T>& counter)
	{
		return false;
	}
	int operator[](const Counter<T>& counter)
	{
		return 0;
	}
	Counter operator||(const Counter<T>& counter)
	{
		return Counter();
	}
	std::ostream& operator<<(std::ostream& out)
	{
		return out;
	}
	Counter operator>>(std::istream& in)
	{
		return Counter();
	}
private:
	Item** _table;
	size_t _size;
	size_t _count;
	size_t getHash(const T & key)
	{
		return (size_t)hash(key) % _size;
	}
	void grow()
	{

	}
};