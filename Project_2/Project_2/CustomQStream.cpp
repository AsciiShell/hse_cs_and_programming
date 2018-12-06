#include "CustomQStream.h"

std::ostream& operator<<(std::ostream& out, const QString & str)
{
	return out << str.toStdString();
}

std::istream& operator>>(std::istream& in, QString & str)
{
	std::string s;
	in >> s;
	str = QString::fromStdString(s);
	return in;
}