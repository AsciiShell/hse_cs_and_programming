#pragma once
#include <stdio.h>
#include "qstring.h"

std::ostream& operator<<(std::ostream& out, const QString & str);

std::istream& operator>>(std::istream& in, QString & str);