#include "Ingredient.h"



Ingredient::Ingredient()
{
	name = nullptr;
	measure = gram;
	count = 0;
}

Ingredient::Ingredient(const char * name, Measure measure, unsigned int count)
{
	strcpy(this->name, name);
	this->measure = measure;
	this->count = count;
}

Ingredient::Ingredient(Ingredient & ingredient)
{
	strcpy(this->name, ingredient.name);
	this->measure = ingredient.measure;
	this->count = ingredient.count;
}


Ingredient::~Ingredient()
{
}

char * Ingredient::getName()
{
	return this->name;
}

Measure Ingredient::getMeasure()
{
	return this->measure;
}

int Ingredient::getCount()
{
	return this->count;
}

void Ingredient::setName(const char * name)
{
	strcpy(this->name, name);
}

void Ingredient::setMeasure(Measure measure)
{
	this->measure = measure;
}

void Ingredient::setCount(unsigned int count)
{
	this->count = count;
}
