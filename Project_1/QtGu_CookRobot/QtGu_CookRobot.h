#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGu_CookRobot.h"

class QtGu_CookRobot : public QMainWindow
{
	Q_OBJECT

public:
	QtGu_CookRobot(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGu_CookRobotClass ui;
};
