#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGu_CookRobot.h"
#include <QFileDialog>
#include <QPushButton>
#include <QLabel>

#include "../Project_1/Ingredient.h"
#include "../Project_1/Operation.h"
#include "../Project_1/Queue.h"
#include "../Project_1/QueueItem.h"

class QtGu_CookRobot : public QMainWindow
{
	Q_OBJECT

public:
	QtGu_CookRobot(QWidget *parent = Q_NULLPTR);
	void drawQueue();

public slots:
	void on_pushButton_load_clicked();
	void on_pushButton_dump_clicked();
	void on_pushButton_clear_clicked();
	void on_pushButton_addIngredient_clicked();
	void on_pushButton_addOperation_clicked();
	void on_item_clicked();
private:
	Ui::QtGu_CookRobotClass ui;
	Queue<QueueItem*> _queue;
	QList<QPushButton*> _queueLabels;
	void connects();
};
