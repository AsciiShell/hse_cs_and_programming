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
		Item(const T & k, const size_t & c)
		{
			key = k;
			count = c;
		}
	};
	Counter() {
		_size = DEFAULT_SIZE;
		_table = new Item*[_size];
		for (size_t i = 0; i < _size; i++)
			_table[i] = nullptr;
		_count = 0;
	}
	Counter(const Counter<T> & collection) {
		// TODO
		_size = 0;
		_count = 0;
		_table = nullptr;
	}
	void addKey(const T&key) {
		size_t index, steps;
		do {
			index = getHash(key);
			steps = 0;
			while (!(_table[index] == nullptr || _table[index]->key == key) && steps < MAX_COLLISION_COUNT)
			{
				index = (index + 1) % _size;
				steps += 1;
			}
			if (steps == MAX_COLLISION_COUNT)
				grow();
		} while (steps == MAX_COLLISION_COUNT);
		if (_table[index] == nullptr) {
			_table[index] = new Item(key);
			_count += 1;
		}
		else
			_table[index]->count += 1;

	}
	bool isIn(const T&key) const {
		return findByKey(key, nullptr);
	}
	void remove(const T&key) {
		size_t index = 0;
		if (findByKey(key, index)) {
			delete _table[index];
			_count -= 1;
		}
		else
			throw std::exception("Key not found");
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
		// TODO
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
		return Iterator();// TODO
	}
	Iterator end() const
	{
		return Iterator(nullptr);// TODO
	}

	bool operator==(const Counter<T>& counter)
	{
		bool result = _count == counter._count;
		for (size_t i = 0; i < _size && result; i++)
			if (_table[i])
			{
				T key = _table[i]->key;
				result = counter.isIn(key) && counter[key]->count == operator[key]->count;
			}
		return result;
	}
	size_t operator[](const Counter<T>& counter)
	{
		size_t index = 0;
		if (findByKey(key, index)) {
			return _table[index].count;
		}
		else
			throw std::exception("Key not found");
	}
	Counter operator||(const Counter<T>& counter)
	{
		return Counter();// TODO
	}
	std::ostream& operator<<(std::ostream& out)
	{
		out << "Number of elements: " << _count << std::endl;
		for (size_t i = 0; i < _size; i++)
			if (_table[i])
				out << "Key: " << _table[i]->key << "\tCount: " << _table[i]->count << std::endl;
		return out << "===================" << std::endl;
	}
	Counter operator>>(std::istream& in)
	{
		return Counter();// TODO
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
		size_t oldSize = _size;
		_size *= GROW_RATE;
		Item** table = new Item*[_size];
		for (size_t i = 0; i < _size; i++)
			table[i] = nullptr;
		for (size_t i = 0; i < oldSize; i++)
			if (_table[i])
			{
				size_t index = getHash(_table[i]->key);
				size_t steps = 0;
				while (table[index] != nullptr && steps < MAX_COLLISION_COUNT)
				{
					index = (index + 1) % _size;
					steps += 1;
				}
				if (steps == MAX_COLLISION_COUNT)
					throw std::exception("Super collision error. Algo can't resolve collision");
				else
					table[index] = _table[i];
			}
		delete[] _table;
		_table = table;
	}
	bool findByKey(const T & key, size_t * result)
	{
		size_t index = getHash(key);
		size_t steps = 0;
		while ((_table[index] == nullptr || _table[index]->key != key) && steps < MAX_COLLISION_COUNT)
		{
			index = (index + 1) % _size;
			steps += 1;
		}
		if (steps != MAX_COLLISION_COUNT && result != nullptr)
			*result = index;
		return steps != MAX_COLLISION_COUNT;
	}
};