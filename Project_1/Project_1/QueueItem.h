#pragma once
#include <QJsonObject>

class QueueItem
{
public:
	enum ItemKind { ITEM_INGREDIENT, ITEM_OPERATION };
	ItemKind getKind() const;
	QueueItem();
	virtual ~QueueItem();
	virtual QJsonObject serialize() = 0;
	virtual void print(std::ostream& out) const = 0;
	virtual QString toString() const = 0;
/*	virtual bool equal(const QueueItem& obj)const = 0;*/
	friend std::ostream& operator<<(std::ostream& out, const QueueItem&value) {
		value.print(out);
		return out;
	}
protected:
	virtual void deserialize(const QJsonObject& object) = 0;
	ItemKind _kind;
};

