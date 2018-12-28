#pragma once
#include <iostream>
template <class T>
class Connector
{
public:
	Connector()
	{
		_id = std::declval<T>();
		_isConnected = false;
	}
	Connector(T id)
	{
		_id = id;
		_isConnected = false;
	}
	virtual ~Connector()
	{

	}
	T getId() const
	{
		return _id;
	}
	virtual bool getType() const = 0;
	bool isConnectable(Connector<T>& connector) const
	{
		return (_id == connector._id) && (getType() != connector.getType()) && !(_isConnected || connector._isConnected);
	}
	bool connect(Connector<T>& connector)
	{
		if (isConnectable(connector))
		{
			_isConnected = true;
			connector._isConnected = true;
			return true;
		}
		return false;
	}
	bool isConnected() const
	{
		return _isConnected;
	}
private:
	T _id;
	bool _isConnected;
};

template <class T>
class Male :public Connector<T>
{
public:
	Male() :Connector<T>()
	{

	}
	Male(T id) :Connector<T>(id)
	{

	}
	Male(Male<T>* male) :Connector<T>(male->getId())
	{

	}
	virtual ~Male() override
	{

	}
	virtual bool getType() const override
	{
		return false;
	}
};

template <class T>
class Female :public Connector<T>
{
public:
	Female() :Connector<T>()
	{

	}
	Female(T id) :Connector<T>(id)
	{

	}
	Female(Female<T>* female) :Connector<T>(female->getId())
	{

	}
	virtual ~Female() override
	{

	}
	virtual bool getType() const override
	{
		return true;
	}
};
