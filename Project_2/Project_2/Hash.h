#pragma once
#include "qstring.h"
const int DELIMITER = 1000000007;
const int BASE = -1902945678;

int hash(const QString & s);
int hash(const std::string& s);

template <class T>
int hash(const T& obj)
{
	int result = BASE;
	uchar* bytes = (uchar*)(&obj);
	for (int i = 0; i < sizeof(T); i++)
		result = result * BASE + DELIMITER * bytes[i];
	return result;
}

