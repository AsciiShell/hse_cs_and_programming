#pragma once
#include <assert.h>
#include "Counter.h"
const int BASE_ITEM = 10;

void testConstructorDefault() {
	Counter<int> c;
	assert(c.getCount() == 0);
}
void testAddItem() {
	Counter<int> c;
	c.addKey(BASE_ITEM);
	assert(c.getCount() == 1);

	size_t oldCount = c.getCount();
	c.addKey(BASE_ITEM);
	assert(c.getCount() == oldCount);
}
void testIn() {
	Counter<int> c;
	c.addKey(BASE_ITEM);
	assert(c.isIn(BASE_ITEM));
}
void testRemove() {
	Counter<int> c;
	c.addKey(BASE_ITEM);
	c.addKey(BASE_ITEM + 1);
	size_t oldCount = c.getCount();
	c.remove(BASE_ITEM);
	assert(c.getCount() == oldCount - 1);
	c.remove(BASE_ITEM);
	assert(c.getCount() == oldCount - 1);
}
void testNotIn() {
	Counter<int> c;
	c.addKey(BASE_ITEM + 1);
	assert(!c.isIn(BASE_ITEM));
}
void testEmptyEqual() {
	Counter<int> c1, c2;
	c1.addKey(BASE_ITEM);
	c1.addKey(BASE_ITEM + 1);
	c1.clear();
	assert(c1 == c2);
}
void testIndex() {
	Counter<int> c;
	c.addKey(BASE_ITEM);
	assert(c[BASE_ITEM] == 1);
}
void testDifferentMerge() {
	Counter<int> c1, c2;

	c1.addKey(BASE_ITEM);
	c1.addKey(BASE_ITEM + 1);

	c2.addKey(BASE_ITEM - 1);
	c2.addKey(BASE_ITEM - 2);
	assert((c1 || c2).getCount() == (c1.getCount() + c2.getCount()));
}
void testEqualtMerge() {
	Counter<int> c1;
	c1.addKey(BASE_ITEM);
	c1.addKey(BASE_ITEM + 1);
	c1.addKey(BASE_ITEM + 2);
	c1.addKey(BASE_ITEM + 3);
	Counter<int> c2(c1);

	assert((c1 || c2).getCount() == c1.getCount());
}
void testCopyConstructor() {
	Counter<int> c1;
	c1.addKey(BASE_ITEM);
	c1.addKey(BASE_ITEM + 1);
	c1.addKey(BASE_ITEM + 2);
	c1.addKey(BASE_ITEM + 3);
	Counter<int> c2(c1);
	assert(c1 == c2);
	c2.addKey(BASE_ITEM + 3);
	assert(c1 != c2);
}
void testLeft() {
	// TODO
}
void testRight() {
	// TODO
}
void testIterator() {
	// TODO
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
	testLeft();
	testRight();
	testIterator();
}