#pragma once
#include "Measure_unit.h"
#include <stdio.h>
#include <iostream>
class Ingredient
{
public:
	Ingredient();
	Ingredient(const char* newName, const Measure newMeasure, const int newCount);
	Ingredient(const Ingredient &ingredient);
	~Ingredient();
	const char* getName()const;
	const Measure getMeasure()const;
	const int getCount()const;
	void setName(const char* newName);
	void setMeasure(const Measure newMeasure);
	void setCount(const int newCount);
private:
	char* name;
	Measure measure;
	int count;
};

