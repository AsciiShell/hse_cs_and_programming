// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "CustomQStream.h"

std::ostream& operator<<(std::ostream& out, const QString & str)
{
	return out << str.toStdString();
}

std::istream& operator>>(std::istream& in, QString & str)
{
	std::string s;
	std::getline(in, s);
	str = QString::fromStdString(s);
	return in;
}