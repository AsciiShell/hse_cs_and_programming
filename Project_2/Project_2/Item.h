#pragma once
#include <iostream>

template <class T>
struct Item {
	T key;
	size_t count;
	Item(const T & k, const size_t & c = 1)
	{
		key = k;
		count = c;
	}
	friend std::ostream& operator<<(std::ostream& out, const Item & item)
	{
		return out << item.key << " "
			<< static_cast<__int64>(item.count) << std::endl;
	}
};