#include "Ingredient.h"
Ingredient::Ingredient()
{
	name = nullptr;
	measure = gram;
	count = 0;
}

Ingredient::Ingredient(const char * newName, const Measure newMeasure, const int newCount)
{
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
	measure = newMeasure;
	if (newCount >= 0)
		count = newCount;
	else
		count = 0;
}

Ingredient::Ingredient(Ingredient & ingredient)
{
	name = new char[strlen(ingredient.name) + 1];
	strcpy(name, ingredient.name);
	measure = ingredient.measure;
	count = ingredient.count;
}

Ingredient::~Ingredient()
{
	if (name != nullptr)
		delete[] name;
}

const char * Ingredient::getName()const
{
	return name;
}

Measure Ingredient::getMeasure()const
{
	return measure;
}

int Ingredient::getCount() const
{
	return count;
}

void Ingredient::setName(const char * newName)
{
	if (name != nullptr)
		delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void Ingredient::setMeasure(const Measure newMeasure)
{
	measure = newMeasure;
}

void Ingredient::setCount(const int newCount)
{
	if (newCount >= 0)
		count = newCount;
}
