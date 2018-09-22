#pragma once
#include "Measure_unit.h"
#include <stdio.h>
#include <iostream>
class Ingredient
{
public:
	Ingredient();
	Ingredient(const char* name, Measure measure, unsigned int count);
	Ingredient(Ingredient &ingredient);
	~Ingredient();
	char* getName();
	Measure getMeasure();
	int getCount();
	void setName(const char* name);
	void setMeasure(Measure measure);
	void setCount(unsigned int count);
private:
	char* name;
	Measure measure;
	unsigned int count;
};

