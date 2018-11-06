#include "Ingredient.h"
Ingredient::Ingredient()
{
	_name = QString();
	_measure = GRAM;
	_count = 0;
}

Ingredient::Ingredient(const QString name, const Measure measure, const int count)
{
	_name = name;
	_measure = measure;
	if (count > 0)
		_count = count;
	else
		_count = 0;
}

Ingredient::Ingredient(const QJsonObject json)
{
	deserialize(json);
}

Ingredient::Ingredient(const Ingredient & ingredient)
{
	_name = ingredient.getName();
	_measure = ingredient.getMeasure();
	_count = ingredient.getCount();
}

Ingredient::~Ingredient()
{
}

const QString Ingredient::getName() const
{
	return _name;
}

Ingredient::Measure Ingredient::getMeasure() const
{
	return _measure;
}

int Ingredient::getCount() const
{
	return _count;
}

void Ingredient::setName(const QString name)
{
	if (!name.isEmpty())
		_name = name;
}

void Ingredient::setMeasure(const Measure measure)
{
	_measure = measure;
}

void Ingredient::setCount(const int count)
{
	if (count >= 0)
		_count = count;
}

bool Ingredient::operator==(const Ingredient ingredient) const
{
	return _name == ingredient._name && _measure == ingredient._measure && _count == ingredient._count;
}

QJsonObject Ingredient::serialize()
{
	QJsonObject jsonObject;
	jsonObject["name"] = _name;
	jsonObject["measure"] = _measure;
	jsonObject["count"] = _count;
	return jsonObject;
}

void Ingredient::deserialize(const QJsonObject object)
{
	_name = object["name"].toString();
	_measure = static_cast<Ingredient::Measure>(object["measure"].toInt());
	_count = object["count"].toInt();
	if (_count < 0)
		_count = 0;
}

std::ostream & operator<<(std::ostream & out, const Ingredient::Measure & value)
{
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

std::ostream & operator<<(std::ostream & out, const Ingredient & value)
{
	return out << value.getName().toStdString() << ": " << value.getCount() << " " << value.getMeasure();

}
