#pragma once
#include <stdio.h>
#include <iostream>
#include <QString>
#include "QueueItem.h"

class Ingredient : public QueueItem
{
public:
	enum Measure
	{
		GRAM,
		MILLILITER,
		PIECE
	};

	Ingredient();
	Ingredient(const QString name, const Measure measure, const int count);
	Ingredient(const QJsonObject json);
	Ingredient(const Ingredient &ingredient);
	~Ingredient();
	const QString getName() const;
	Measure getMeasure() const;
	int getCount() const;
	void setName(const QString name);
	void setMeasure(const Measure measure);
	void setCount(const int count);
	bool operator==(const Ingredient ingredient) const;
	// Унаследовано через QueueItem
	virtual QJsonObject serialize() override;
private:
	virtual void deserialize(const QJsonObject object) override;
	QString _name;
	Measure _measure;
	int _count;


};

std::ostream& operator<<(std::ostream& out, const Ingredient::Measure  &value);
std::ostream& operator<<(std::ostream& out, const Ingredient  &value);