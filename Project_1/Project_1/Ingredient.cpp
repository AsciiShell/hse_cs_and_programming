#include "Ingredient.h"
Ingredient::Ingredient()
{
	_name = QString();
	_measure = GRAM;
	_count = 0;
}

Ingredient::Ingredient(const QString name, const Measure measure, const int count)
{
	_name = name;
	_measure = measure;
	if (count > 0)
		_count = count;
	else
		_count = 0;
}

Ingredient::Ingredient(const Ingredient & ingredient)
{
	_name = ingredient.getName();
	_measure = ingredient.getMeasure();
	_count = ingredient.getCount();
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
