#include "QtGu_CookRobot.h"

QtGu_CookRobot::QtGu_CookRobot(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.groupBox_ingredient->setVisible(false);
	ui.groupBox_operation->setVisible(false);
	_queue = Queue<QueueItem*>::load("dump.json");
}
