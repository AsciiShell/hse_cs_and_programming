#pragma once
#include <assert.h>
#include <fstream>
#include "Counter.h"
const QString BASE_ITEM = "QWE";
const std::string FILENAME = "test.txt";

void testConstructorDefault() {
	Counter<QString> c;
	assert(c.getCount() == 0);
}
void testAddItem() {
	Counter<QString> c;
	c.addKey(BASE_ITEM);
	assert(c.getCount() == 1);

	size_t oldCount = c.getCount();
	c.addKey(BASE_ITEM);
	assert(c.getCount() == oldCount);
}
void testIn() {
	Counter<QString> c;
	c.addKey(BASE_ITEM);
	assert(c.isIn(BASE_ITEM));
}
void testRemove() {
	Counter<QString> c;
	c.addKey(BASE_ITEM);
	c.addKey(BASE_ITEM + 1);
	size_t oldCount = c.getCount();
	c.remove(BASE_ITEM);
	assert(c.getCount() == oldCount - 1);
	c.remove(BASE_ITEM);
	assert(c.getCount() == oldCount - 1);
}
void testNotIn() {
	Counter<QString> c;
	c.addKey(BASE_ITEM + 1);
	assert(!c.isIn(BASE_ITEM));
}
void testEmptyEqual() {
	Counter<QString> c1, c2;
	c1.addKey(BASE_ITEM);
	c1.addKey(BASE_ITEM + 1);
	c1.clear();
	assert(c1 == c2);
}
void testIndex() {
	Counter<QString> c;
	c.addKey(BASE_ITEM);
	assert(c[BASE_ITEM] == 1);
}
void testDifferentMerge() {
	Counter<QString> c1, c2;

	c1.addKey(BASE_ITEM);
	c1.addKey(BASE_ITEM + 1);

	c2.addKey(BASE_ITEM + "1");
	c2.addKey(BASE_ITEM + "2");
	assert((c1 || c2).getCount() == (c1.getCount() + c2.getCount()));
}
void testEqualtMerge() {
	Counter<QString> c1;
	c1.addKey(BASE_ITEM);
	c1.addKey(BASE_ITEM + "1");
	c1.addKey(BASE_ITEM + "2");
	c1.addKey(BASE_ITEM + "3");
	Counter<QString> c2(c1);

	assert((c1 || c2).getCount() == c1.getCount());
}
void testCopyConstructor() {
	Counter<QString> c1;
	c1.addKey(BASE_ITEM);
	c1.addKey(BASE_ITEM + "1");
	c1.addKey(BASE_ITEM + "2");
	c1.addKey(BASE_ITEM + "3");
	Counter<QString> c2(c1);
	assert(c1 == c2);
	c2.addKey(BASE_ITEM + 3);
	assert(c1 != c2);
}
void testFile() {
	Counter<QString> c1, c2;
	c1.addKey(BASE_ITEM);
	c1.addKey(BASE_ITEM + "1");
	c1.addKey(BASE_ITEM + "2");
	c1.addKey("Mohammad bin Salman");

	std::ofstream ofile;
	ofile.open(FILENAME);
	ofile << c1;
	ofile.close();

	std::ifstream ifile;
	ifile.open(FILENAME);
	ifile >> c2;
	ifile.close();

	assert(c1 == c2);
	c2.addKey(BASE_ITEM + 3);
	assert(c1 != c2);
}
void testIterator() {
	Counter<QString> c;
	for (int i = 0; i < 1000; i++)
		c.addKey(BASE_ITEM + QString::number(rand() % 10), rand() % 5);
	std::cout << std::endl << "Start Iterator" << std::endl;
	for (auto i = c.begin(); i != c.end(); i++)
		std::cout << i.getKey() << ": \t" << i.getValue() << std::endl;
	std::cout << "End Iterator" << std::endl << "TOP 5" << std::endl;
	std::cout << c.getTopN(5);
}
void testMemoryLeak() {
	for (size_t i = 0; i < 5; i++)
	{
		Counter<QString> c;
		for (int i = 0; i < 100000; i++)
			c.addKey(BASE_ITEM + QString::number(rand()), rand() % 5);
		for (int i = 0; i < 100000; i++)
			c.remove(BASE_ITEM + QString::number(rand()));
	}
	for (size_t i = 0; i < 500; i++)
	{
		Counter<QString> c;
		for (int i = 0; i < 1000; i++)
			c.addKey(BASE_ITEM + QString::number(rand() % 10), rand() % 5);
		for (int i = 0; i < 1000; i++)
			c.remove(BASE_ITEM + QString::number(rand() % 10));
	}

	// Look into profiler
}
void test() {
	testConstructorDefault();
	testAddItem();
	testIn();
	testRemove();
	testNotIn();
	testEmptyEqual();
	testIndex();
	testDifferentMerge();
	testEqualtMerge();
	testCopyConstructor();
	testFile();
	testIterator();
	testMemoryLeak();
}