#pragma once
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
	virtual ~Ingredient();
	const QString getName() const;
	Measure getMeasure() const;
	int getCount() const;
	void setName(const QString name);
	void setMeasure(const Measure measure);
	void setCount(const int count);
	bool operator==(const Ingredient ingredient) const;
	virtual void print(std::ostream& out) const override;
	friend std::ostream& operator<<(std::ostream& out, const Ingredient::Measure  &value) {
		switch (value)
		{
		case Ingredient::Measure::GRAM:
			return out << "gramms";
			break;
		case Ingredient::Measure::MILLILITER:
			return out << "milliliters";
			break;
		case Ingredient::Measure::PIECE:
			return out << "pieces";
			break;
		default:
			return out << "unknown";
			break;
		}
	}
	friend std::ostream& operator<<(std::ostream& out, const Ingredient  &value) {
		value.print(out);
		return out;
	}
	virtual QJsonObject serialize() override;
private:
	virtual void deserialize(const QJsonObject object) override;
	QString _name;
	Measure _measure;
	int _count;


};