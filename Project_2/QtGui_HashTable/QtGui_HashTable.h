#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGui_HashTable.h"

class QtGui_HashTable : public QMainWindow
{
	Q_OBJECT

public:
	QtGui_HashTable(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGui_HashTableClass ui;
};
