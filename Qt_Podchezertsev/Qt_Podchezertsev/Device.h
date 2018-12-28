#pragma once
#include "qstring.h"
#include "Connector.h"

template <class T>
class Device
{
public:
	Device()
	{
		_name = "";
		_size = _count = 0;
		_connectors = nullptr;
	}
	Device(QString name, size_t size) :_name(name)
	{
		_size = size;
		_count = 0;
		_connectors = new Connector<int>*[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_connectors[i] = nullptr;
		}
	}
	Device(const Device<T>& device) :_name(device._name)
	{
		_size = device._size;
		_count = 0;
		_connectors = new Connector<int>*[_size];
		for (size_t i = 0; i < device._count; i++)
		{
			addConnector(*device._connectors[i]);
		}
	}
	~Device()
	{
		clear();
		delete[] _connectors;
	}
	class Iterator {
	public:
		Iterator(Connector<T>** ptr, size_t size) {
			_ptr = ptr;
			start = size;
			index = 0;
		}
		~Iterator() {}
		Iterator operator++(int) {
			Iterator i = *this;
			index++;
			return i;
		}
		Iterator& operator++() {
			index++;
			return *this;
		}
		Connector<T>* operator*() const {
			return _ptr[index + start];
		}
		bool operator==(const Iterator& rhs) const {
			return _ptr == rhs._ptr && (index + start) == (rhs.index + rhs.start);
		}
		bool operator!=(const Iterator& rhs) const {
			return !(_ptr == rhs._ptr && (index + start) == (rhs.index + rhs.start));
		}
	private:
		Connector<T>** _ptr;
		size_t index, start;
	};
	Iterator begin() const
	{
		return Iterator(_connectors, 0);
	}
	Iterator end() const
	{
		return Iterator(_connectors, _count);
	}
	void addConnector(Connector<T>& connector)
	{
		if (_count < _size)
		{
			if (connector.getType())
				_connectors[_count] = new Male<T>(static_cast<Male<T>*>(&connector));
			else
				_connectors[_count] = new Female<T>(static_cast<Female<T>*>(&connector));
			_count++;
		}

	}
	void fillRandomConnector(int maxID = INT16_MAX)
	{
		for (; _count < _size; _count++)
		{
			if (rand() % 2)
			{
				_connectors[_count] = new Male<T>(rand() % maxID);
			}
			else
			{
				_connectors[_count] = new Female<T>(rand() % maxID);
			}
		}
	}
	void clear()
	{
		for (size_t i = 0; i < _count; i++)
		{
			delete _connectors[i];
			_connectors[i] = nullptr;
		}
	}
	size_t getCount() const
	{
		return _count;
	}
	Device<T> operator+(Device<T> device)
	{
		Device<T> result(_name + " & " + device._name, _count + device._count);
		for (size_t i = 0; i < _count; i++)
		{
			for (size_t j = 0; j < device._count; j++)
			{
				// Try to connect some pair
				_connectors[i]->connect(*(device._connectors[j]));
			}
			if (!_connectors[i]->isConnected())
				result.addConnector(*(_connectors[i]));
		}
		for (size_t i = 0; i < device._count; i++)
		{
			if (!device._connectors[i]->isConnected())
				result.addConnector(*(device._connectors[i]));
		}

		return result;
	}
	QString getName() const
	{
		return _name;
	}
private:
	QString _name;
	size_t _size, _count;
	Connector<T>** _connectors;
};

