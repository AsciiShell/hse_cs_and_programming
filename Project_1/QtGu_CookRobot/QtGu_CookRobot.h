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
#include "../Project_1/itemStuff.h"

class QtGu_CookRobot : public QMainWindow
{
	Q_OBJECT

public:
	QtGu_CookRobot(QWidget *parent = Q_NULLPTR);
	void drawQueue();
	void setEmptyLayout();
	void setIngredientLayout(Ingredient* item);
	void setOperationLayout(Operation* item);

public slots:
	void on_pushButton_load_clicked();
	void on_pushButton_dump_clicked();
	void on_pushButton_clear_clicked();
	void on_pushButton_addIngredient_clicked();
	void on_pushButton_addOperation_clicked();
	void on_pushButton_pop_clicked();
	void on_item_clicked();
	void on_pushButton_apply();
	void on_pushButton_delete();
private:
	Ui::QtGu_CookRobotClass ui;
	Queue<QueueItem*> _queue;
	QList<QPushButton*> _queueItems;
	Ingredient* _ingredient;
	Operation* _operation;
	QVBoxLayout *verticalLayout_queue;
	void connects();
	void setControlLayout();
};
