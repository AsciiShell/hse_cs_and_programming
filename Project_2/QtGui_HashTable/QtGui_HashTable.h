#pragma once
#include <stdio.h>
#include <QtWidgets/QMainWindow>
#include "QStandardItemModel"
#include "QStandardItem"
#include "ui_QtGui_HashTable.h"
#include "../Project_2/Counter.h"

class QtGui_HashTable : public QMainWindow
{
	Q_OBJECT

public:
	QtGui_HashTable(QWidget *parent = Q_NULLPTR);
public slots:
	void on_pushButton_addItem_clicked();
	void on_pushButton_findKey_clicked();
	void on_pushButton_clear_clicked();
	void on_pushButton_getTop_clicked();
	void on_pushButton_editItem_save_clicked();
	void on_pushButton_editItem_remove_clicked();
	void on_table_clicked(const QModelIndex &index);
private:
	Ui::QtGui_HashTableClass ui;
	Counter<QString> _counter;
	void drawTable();
	void setEditLayout(bool display);
};
