// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "Hash.h"
int hash(const std::string& s) {
	int result = BASE;
	for (size_t i = 0; i < s.length(); i++)
		result = result * BASE + DELIMITER * s[i];
	return result;
}

int hash(const QString& s) {
	return hash(s.toStdString());
}
