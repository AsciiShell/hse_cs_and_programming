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


void Queue::dump(QString filepath) const
{
	QJsonArray json_array;
	for (auto i = begin(); i < end(); i++)
	{
		QJsonObject json_object;
		json_object["name"] = i->getName();
		json_object["measure"] = i->getMeasure();
		json_object["count"] = i->getCount();
		json_array.append(json_object);
	}
	QJsonDocument json_doc(json_array);
	QFile file(filepath);
	file.open(QIODevice::WriteOnly);
	file.write(json_doc.toJson());
	file.close();
}

Queue Queue::load(QString filepath)
{
	QFile file(filepath);
	file.open(QIODevice::ReadOnly);
	QJsonArray json_array = QJsonDocument::fromJson(file.readAll()).array();
	Queue queue;
	for (auto i = 0; i < json_array.count(); i++) {
		QJsonObject json_ingredient = json_array.at(i).toObject();
		queue.push(Ingredient(json_ingredient["name"].toString(), (Ingredient::Measure)json_ingredient["measure"].toInt(), json_ingredient["count"].toInt()));
	}
	return queue;
}
