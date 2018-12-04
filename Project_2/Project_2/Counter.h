#pragma once
#include "CustomQStream.h"
#include "Hash.h"
#include "Item.h"
#include "Queue.h"
template <class T>
class Counter
{
private:
	static const size_t DEFAULT_SIZE = 16;
	static const size_t GROW_RATE = 3;
	static const size_t MAX_COLLISION_COUNT = 3;

public:

	Counter() {
		_size = DEFAULT_SIZE;
		_table = new Item<T>*[_size];
		for (size_t i = 0; i < _size; i++)
			_table[i] = nullptr;
		_count = 0;
	}
	Counter(const Counter<T> & collection) {
		_size = collection._count * GROW_RATE;
		_count = 0;
		_table = new Item<T>*[_size];
		for (size_t i = 0; i < _size; i++)
			_table[i] = nullptr;
		for (size_t i = 0; i < collection._size; i++)
			if (collection._table[i])
				addKey(collection._table[i]->key, collection._table[i]->count);
	}
	~Counter() {
		clear();
		delete[] _table;
	}
	void addKey(const T&key, const size_t & count = 1) {
		size_t index, steps;
		do {
			index = getHash(key);
			steps = 0;
			while (!(_table[index] == nullptr || _table[index]->key == key)
				&& steps < MAX_COLLISION_COUNT)
			{
				index = (index + 1) % _size;
				steps += 1;
			}
			if (steps == MAX_COLLISION_COUNT)
				grow();
		} while (steps == MAX_COLLISION_COUNT);
		if (_table[index] == nullptr) {
			_table[index] = new Item<T>(key, count);
			_count += 1;
		}
		else
			_table[index]->count += count;
	}
	bool isIn(const T&key) const {
		return findByKey(key, nullptr);
	}
	void remove(const T&key) {
		size_t index = 0;
		if (findByKey(key, &index)) {
			delete _table[index];
			_table[index] = nullptr;
			_count -= 1;
		}
	}
	void clear() {
		for (size_t i = 0; i < _size; i++)
		{
			delete _table[i];
			_table[i] = nullptr;
		}
		_count = 0;
	}
	size_t getCount() const {
		return _count;
	}
	class Iterator {
	public:
		Iterator(size_t start, size_t end, Item<T>** table) {
			_start = start;
			_end = end;
			_table = table;
			while (_table[_start] == nullptr && (_start != _end))
				_start++;
		}
		~Iterator() {}
		Iterator operator++(int) {
			Iterator i = *this;
			do {
				_start++;
			} while (_table[_start] == nullptr && (_start != _end));
			return i;
		}
		Iterator& operator++() {
			do {
				_start++;
			} while (_table[_start] == nullptr && (_start != _end));
			return *this;
		}
		size_t getValue() const
		{
			return _table[_start]->count;
		}
		T getKey() const
		{
			return _table[_start]->key;
		}
		const Item<T>& getItem() const {
			return *(_table[_start]);
		}
		bool operator==(const Iterator& rhs) const {
			return _start == rhs._start && _end == rhs._end && _table == rhs._table;
		}
		bool operator!=(const Iterator& rhs) const {
			return !operator==(rhs);
		}
	private:
		size_t _start, _end;
		Item<T>** _table;
	};
	Iterator begin() const
	{
		return Iterator(0, _size, _table);
	}
	Iterator end() const
	{
		return Iterator(_size, _size, _table);
	}

	bool operator==(const Counter<T>& counter) const
	{
		bool result = _count == counter._count;
		for (size_t i = 0; i < _size && result; i++)
			if (_table[i])
			{
				T key = _table[i]->key;
				result = counter.isIn(key) && counter[key] == _table[i]->count;
			}
		return result;
	}
	bool operator!=(const Counter<T>& counter) const
	{
		return !operator==(counter);
	}
	size_t operator[](const T & key) const //-V302
	{
		size_t index = 0;
		if (findByKey(key, &index)) {
			return _table[index]->count;
		}
		else
			throw std::exception("Key not found");
	}
	Counter operator||(const Counter<T>& counter) const
	{
		Counter result(counter);
		for (auto i = begin(); i != end(); ++i)
			result.addKey(i.getKey(), i.getValue());
		return result;
	}
	Queue<Item<T>> getTopN(const size_t & n) const
	{
		Item<T>** arr = new Item<T>*[_count];
		Item<T> *swap;
		size_t arrayI = 0;
		for (auto i = begin(); i != end(); ++i)
			arr[arrayI++] = const_cast<Item<T>*>(&(i.getItem()));
		for (size_t i = 0; i < n && i < _count; i++)
			for (size_t j = i + 1; j < _count; j++)
				if (arr[j]->count > arr[i]->count) {
					swap = arr[j];
					arr[j] = arr[i];
					arr[i] = swap;
				}
		Queue<Item<T>> result;
		for (size_t i = 0; i < n; i++)
			result.push(*arr[i]);
		delete[] arr;
		return result;
	}
	friend std::ofstream& operator<<(std::ofstream& out,
		const Counter<T>& counter)
	{
		out << static_cast<__int64>(counter._count)
			<< std::endl;
		for (size_t i = 0; i < counter._size; i++)
			if (counter._table[i])
				out << *(counter._table[i]);
		return out;
	}
	friend std::ifstream& operator>>(std::ifstream& in,
		Counter<T>& counter)
	{
		size_t count;
		in >> count; //-V128
		for (size_t i = 0; i < count; i++) {
			T key;
			size_t value;
			in >> key >> value; //-V128
			counter.addKey(key, value);
		}
		return in;
	}
private:
	Item<T>** _table;
	size_t _size;
	size_t _count;
	size_t getHash(const T & key) const
	{
		return (size_t)hash(key) % _size;
	}
	void grow()
	{
		size_t oldSize = _size;
		_size *= GROW_RATE;
		Item<T>** table = new Item<T>*[_size];
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
				{
					// Rollback
					delete[] table;
					_size = oldSize;
					throw std::exception("Super collision error. \
Algo can't resolve collision");
				}
				else
					table[index] = _table[i];
			}
		delete[] _table;
		_table = table;
	}
	bool findByKey(const T & key, size_t * result) const
	{
		size_t index = getHash(key);
		size_t steps = 0;
		while ((_table[index] == nullptr || _table[index]->key != key)
			&& steps < MAX_COLLISION_COUNT)
		{
			index = (index + 1) % _size;
			steps += 1;
		}
		if (steps != MAX_COLLISION_COUNT && result != nullptr)
			*result = index;
		return steps != MAX_COLLISION_COUNT;
	}
};

