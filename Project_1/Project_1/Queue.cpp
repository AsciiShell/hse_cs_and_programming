#include "Queue.h"
typedef Ingredient* iterator;
Queue::Queue()
{
	_tail = _head = _objects = nullptr;
	_count = _allocated = 0;
}

Queue::Queue(const Queue & queue)
{
	_tail = _objects = new Ingredient[queue.getCount()];
	_head = _tail + queue.getCount();
	_allocated = _count = queue.getCount();
	for (auto i = queue.begin(); i < queue.end(); i++)
		_objects[i - queue.begin()] = Ingredient(*i);
}


Queue::~Queue()
{
	if (_allocated)
		delete[] _objects;
}

void Queue::grow(size_t size)
{
	Ingredient *tmp = new Ingredient[_count + size];
	for (auto i = _tail - _objects; i < _count; i++)
		tmp[i] = _tail[i];
	delete[] _objects;
	_tail = _objects = tmp;
	_allocated += size;
	_head = _tail + _count;
}

void Queue::push(Ingredient & ingredient)
{
	if (_head == _objects + _allocated)
		grow();
	*_head = ingredient;
	_head += 1;
	_count += 1;
}

Ingredient& Queue::pop()
{
	if (_count > 0) {
		auto result = *_tail;
		_tail += 1;
		_count -= 1;
		return result;
	}
	else
		throw std::exception("Queue is empty");
}

iterator Queue::begin() const
{
	return _tail;
}

iterator Queue::end() const
{
	return _head;
}

void Queue::clear()
{
	delete[] _objects;
	_head = _objects = _tail = nullptr;
	_allocated = _count = 0;
}

int Queue::getCount() const
{
	return _count;
}


void Queue::dump(const QString filepath) const
{
	QJsonArray jsonArray;
	for (auto i = begin(); i < end(); i++)
	{
		QJsonObject jsonObject;
		jsonObject["name"] = i->getName();
		jsonObject["measure"] = i->getMeasure();
		jsonObject["count"] = i->getCount();
		jsonArray.append(jsonObject);
	}
	QJsonDocument jsonDoc(jsonArray);
	QFile file(filepath);
	file.open(QIODevice::WriteOnly);
	file.write(jsonDoc.toJson());
	file.close();
}

Queue Queue::load(const QString filepath)
{
	QFile file(filepath);
	file.open(QIODevice::ReadOnly);
	QJsonArray jsonArray = QJsonDocument::fromJson(file.readAll()).array();
	Queue queue;
	for (auto i = 0; i < jsonArray.count(); i++) {
		QJsonObject jsonIngredient = jsonArray.at(i).toObject();
		queue.push(Ingredient(jsonIngredient["name"].toString(), (Ingredient::Measure)jsonIngredient["measure"].toInt(), jsonIngredient["count"].toInt()));
	}
	return queue;
}

bool Queue::equal(const Queue &queue) const
{
	bool result = queue.getCount() == _count;
	for (auto i = queue.begin(); i < queue.end() && result; i++)
		result = _objects[i - queue.begin()].equal(*i);
	return result;
}

void printQueue(Queue queue)
{
	for (auto i = queue.begin(); i < queue.end(); i++)
		std::cout << i - queue.begin() + 1 << ": " << *i << std::endl;
}
