#pragma once
#include "qstring.h"
const int DELIMITER = 1000000007;
const int BASE = -1902945678;

template <class T>
int hash(const T& obj)
{
	int result = BASE;
	uchar* bytes = (uchar*)(&obj);
	for (int i = 0; i < sizeof(T); i++)
		result = result * BASE + DELIMITER * bytes[i];
	return result;
}

int hash(const int& i) {
	return ((i << 16) | (i >> 16)) ^ i;
}

int hash(const std::string& s) {
	int result = BASE;
	for (int i = 0; i < s.length(); i++)
		result = result * BASE + DELIMITER * s[i];
	return result;
}

int hash(const QString& s) {
	return hash(s.toStdString());
}
