#include "Test.h"

void testConstructorDafaultName()
{
	Ingredient ingredient;
	assert(ingredient.getName() == nullptr);
}

void testConstructorDafaultMeasure()
{
	Ingredient ingredient;
	assert(ingredient.getMeasure() == gram);
}
void testConstructorDafaultCount()
{
	Ingredient ingredient;
	assert(ingredient.getCount() == 0);
}

void testConstructorInitName()
{
	Ingredient ingredient("Вафли", piece, 10);
	assert(strcmp(ingredient.getName(), "Вафли") == 0);
}

void testConstructorInitMeasure()
{
	Ingredient ingredient("Вафли", piece, 10);
	assert(ingredient.getMeasure() == piece);
}

void testConstructorInitCount()
{
	Ingredient ingredient("Вафли", piece, 10);
	assert(ingredient.getCount() == 10);
}

void testConstructorInitCountWrong()
{
	Ingredient ingredient("Вафли", piece, -10);
	assert(ingredient.getCount() == 0);
}

void testConstructorCopyName()
{
	Ingredient ingredient1("Вафли", piece, 10);
	Ingredient ingredient2(ingredient1);
	assert(strcmp(ingredient1.getName(), ingredient2.getName()) == 0);
}

void testConstructorCopyMeasure()
{
	Ingredient ingredient1("Вафли", piece, 10);
	Ingredient ingredient2(ingredient1);
	assert(ingredient1.getMeasure() == ingredient2.getMeasure());
}

void testConstructorCopyCount()
{
	Ingredient ingredient1("Вафли", Measure::piece, 10);
	Ingredient ingredient2(ingredient1);
	assert(ingredient1.getCount() == ingredient2.getCount());
}

void testSetName()
{
	Ingredient ingredient;
	ingredient.setName("Мука");
	assert(strcmp(ingredient.getName(), "Мука") == 0);
}

void testSetMeasure()
{
	Ingredient ingredient;
	ingredient.setMeasure(milliliter);
	assert(ingredient.getMeasure() == milliliter);
}

void testSetCount()
{
	Ingredient ingredient;
	ingredient.setCount(127);
	assert(ingredient.getCount() == 127);
}

void testSetCountWrong()
{
	Ingredient ingredient;
	ingredient.setCount(-127);
	assert(ingredient.getCount() != -127);
}

void runTests()
{
	testConstructorDafaultName();
	testConstructorDafaultMeasure();
	testConstructorDafaultCount();

	testConstructorInitName();
	testConstructorInitMeasure();
	testConstructorInitCount();
	testConstructorInitCountWrong();

	testConstructorCopyName();
	testConstructorCopyMeasure();
	testConstructorCopyCount();

	testSetName();
	testSetMeasure();
	testSetCount();
	testSetCountWrong();
	printf("All tests passed successfully!\n");
}