// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "Ingredient.h"
Ingredient::Ingredient()
{
	_name = QString();
	_measure = GRAM;
	_count = 0;
	_kind = ITEM_INGREDIENT;
}

Ingredient::Ingredient(const QString name, const Measure measure, const int count)
{
	_name = name;
	_measure = measure;
	_kind = ITEM_INGREDIENT;
	if (count > 0)
		_count = count;
	else
		_count = 0;
}

Ingredient::Ingredient(const QJsonObject json)
{
	_kind = ITEM_INGREDIENT;
	deserialize(json);
}

Ingredient::Ingredient(const Ingredient & ingredient)
{
	_kind = ITEM_INGREDIENT;
	_name = ingredient._name;
	_measure = ingredient._measure;
	_count = ingredient._count;
}

Ingredient::~Ingredient()
{
}

const QString Ingredient::getName() const
{
	return _name;
}

Ingredient::Measure Ingredient::getMeasure() const
{
	return _measure;
}

int Ingredient::getCount() const
{
	return _count;
}

void Ingredient::setName(const QString name)
{
	if (!name.isEmpty())
		_name = name;
}

void Ingredient::setMeasure(const Measure measure)
{
	_measure = measure;
}

void Ingredient::setCount(const int count)
{
	if (count >= 0)
		_count = count;
}

bool Ingredient::operator==(const Ingredient ingredient) const
{
	return _name == ingredient._name && _measure == ingredient._measure && _count == ingredient._count;
}

void Ingredient::print(std::ostream & out) const
{
	out << _name.toStdString() << ": " << _count << " " << _measure;
}

QJsonObject Ingredient::serialize()
{
	QJsonObject jsonObject;
	jsonObject["name"] = _name;
	jsonObject["measure"] = _measure;
	jsonObject["count"] = _count;
	jsonObject["kind"] = ITEM_INGREDIENT;
	return jsonObject;
}

void Ingredient::deserialize(const QJsonObject object)
{
	_name = object["name"].toString();
	_measure = static_cast<Ingredient::Measure>(object["measure"].toInt());
	_count = object["count"].toInt();
	if (_count < 0)
		_count = 0;
}
