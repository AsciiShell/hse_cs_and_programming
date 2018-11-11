#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGu_CookRobot.h"
#include "../Project_1/Ingredient.h"
#include "../Project_1/Operation.h"
#include "../Project_1/Queue.h"
#include "../Project_1/QueueItem.h"

class QtGu_CookRobot : public QMainWindow
{
	Q_OBJECT

public:
	QtGu_CookRobot(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGu_CookRobotClass ui;
	Queue<QueueItem*> _queue;
};
