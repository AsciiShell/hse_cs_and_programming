#pragma once
#include "QueueItem.h"
#include "GC.h"
#include "Ingredient.h"
#include "Operation.h"
#include "Queue.h"
#include <assert.h>
#include "itemStuff.h"

GC<QueueItem> gc;

Queue<QueueItem*> generateQueue() {
	Queue<QueueItem*> queue;
	QueueItem* item = static_cast<QueueItem*>(new Ingredient("Potato", Ingredient::GRAM, 100));
	gc.add(item);
	queue.push(item);

	item = static_cast<QueueItem*>(new Ingredient("Milk", Ingredient::MILLILITER, 500));
	gc.add(item);
	queue.push(item);

	item = static_cast<QueueItem*>(new Ingredient("Salt", Ingredient::GRAM, 5));
	gc.add(item);
	queue.push(item);

	item = static_cast<QueueItem*>(new Ingredient("Sugar", Ingredient::GRAM, 10));
	gc.add(item);
	queue.push(item);

	item = static_cast<QueueItem*>(new Ingredient("Butter", Ingredient::GRAM, 180));
	gc.add(item);
	queue.push(item);

	item = static_cast<QueueItem*>(new Ingredient("Tea bag", Ingredient::PIECE, 3));
	gc.add(item);
	queue.push(item);

	item = static_cast<QueueItem*>(new Operation(Operation::Action::FRY, 120));
	gc.add(item);
	queue.push(item);

	item = static_cast<QueueItem*>(new Operation(Operation::Action::PACK, 10));
	gc.add(item);
	queue.push(item);
	return queue;
}

void testCopyConstructor() {
	Queue<QueueItem*> queue1 = generateQueue();
	Queue<QueueItem*> queue2(queue1);
	assert(queue2.equal(queue1));
	QueueItem* object = queue2.pop();
	queue2.push(object);
	assert(!queue2.equal(queue1));
}

void testAppend() {
	Queue<QueueItem*> queue = generateQueue();
	int lastSize = queue.getCount();
	QueueItem* item = static_cast<QueueItem*>(new Ingredient());
	gc.add(item);
	queue.push(item);
	assert(queue.getCount() == lastSize + 1);
}

void testRemove() {
	Queue<QueueItem*> queue = generateQueue();
	int lastSize = queue.getCount();
	queue.pop();
	assert(queue.getCount() == lastSize - 1);
}

void testClear() {
	Queue<QueueItem*> queue = generateQueue();
	queue.clear();
	assert(queue.getCount() == 0);
}
void testFile() {
	Queue<QueueItem*> queue1 = generateQueue();
	QString filename = "dump.json";
	queue1.dump(filename);
	Queue<QueueItem*> queue2 = Queue<QueueItem*>();
	queue2.load(filename);
	assert(queue1.equal(queue2));
}

void testAccess() {
	printQueue(generateQueue());
}

void testExtendedOverread() {
	Queue<QueueItem*> queue;
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

void testMemoryLeak() {
	Queue<QueueItem*> queue;
	for (int i = 0; i < 1000000; i++)
	{
		QueueItem*  item = static_cast<QueueItem*>(new Operation());
		gc.add(item);
		queue.push(item);
		queue.pop();
		gc.clear();
	}
}
void runTestsQueue() {
	testCopyConstructor();
	testAppend();
	testRemove();
	testClear();
	testFile();
	testAccess();
	testExtendedOverread();
	testMemoryLeak();
	gc.clear();
}