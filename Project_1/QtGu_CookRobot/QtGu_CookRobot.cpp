// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "QtGu_CookRobot.h"

QtGu_CookRobot::QtGu_CookRobot(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.groupBox_ingredient->setVisible(false);
	ui.groupBox_operation->setVisible(false);
	_queue.load("dump.json");
	foreach(QLabel* el, ui.groupBox_queue->findChildren<QLabel*>()) {
		delete el;
	}
	auto i = _queue.begin();
	int number = 1;
	for (; i != _queue.end(); i++, number++) {
		QLabel *labelQueueItem = new QLabel(ui.groupBox_queue);

		labelQueueItem->setText(QString::number(number) + ": " + (*i)->toString());
		labelQueueItem->setGeometry(10, 20 * number, 180, 20);
	}
	ui.groupBox_queue->setFixedHeight(20 * number);
}

void QtGu_CookRobot::paintEvent(QPaintEvent * event)
{

}
