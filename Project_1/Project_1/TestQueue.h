#pragma once
#include "Ingredient.h"
#include "Queue.h"
#include <assert.h>

Queue generateQueue() {
	Queue queue;
	queue.push(Ingredient("Potato", Ingredient::GRAM, 100));
	queue.push(Ingredient("Milk", Ingredient::MILLILITER, 500));
	queue.push(Ingredient("Salt", Ingredient::GRAM, 5));
	queue.push(Ingredient("Sugar", Ingredient::GRAM, 10));
	queue.push(Ingredient("Butter", Ingredient::GRAM, 180));
	queue.push(Ingredient("Tea bag", Ingredient::PIECE, 3));
	return queue;
}

void testCopyConstructor() {
	Queue queue1 = generateQueue();
	Queue queue2(queue1);
	assert(queue2.equal(queue1));
	Ingredient ingredient = queue2.pop();
	queue2.push(ingredient);
	assert(!queue2.equal(queue1));
}

void testAppend() {
	Queue queue = generateQueue();
	int lastSize = queue.getCount();
	queue.push(Ingredient());
	assert(queue.getCount() == lastSize + 1);
}

void testRemove() {
	Queue queue = generateQueue();
	int lastSize = queue.getCount();
	queue.pop();
	assert(queue.getCount() == lastSize - 1);
}

void testClear() {
	Queue queue = generateQueue();
	queue.clear();
	assert(queue.getCount() == 0);
}
void testFile() {
	Queue queue1 = generateQueue();
	QString filename = "dump.json";
	queue1.dump(filename);
	Queue queue2 = Queue::load(filename);
	assert(queue1.equal(queue2));
}

void testAccess() {
	printQueue(generateQueue());
}

void testExtendedOverread() {
	Queue queue;
	while (queue.getCount())
		queue.pop();
	bool raised = false;
	try
	{
		queue.pop();
	}
	catch (const std::exception& e)
	{
		raised = true;
	}
	assert(raised);
}
void runTestsQueue() {
	testCopyConstructor();
	testAppend();
	testRemove();
	testClear();
	testFile();
	testAccess();
	testExtendedOverread();
	printf("All tests passed successfully");
}