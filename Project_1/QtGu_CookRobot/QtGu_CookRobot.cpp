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

	_queueLabels = QList<QPushButton*>();
	for (int i = 0; i < 100; i++)
	{
		QPushButton *label = new QPushButton(ui.groupBox_queue);
		label->setText("");
		label->setGeometry(QRect(10, 20 * (i + 1), 180, 20));
		_queueLabels.push_back(label);
		connect(label, SIGNAL(clicked()), this, SLOT(on_item_clicked()));
	}
	drawQueue();
	QRegExp int_exp("[0-9]*");
	ui.lineEdit_ingredientCount->setValidator(new QRegExpValidator(int_exp, this));
	ui.lineEdit_operationDuration->setValidator(new QRegExpValidator(int_exp, this));
	connects();
}

void QtGu_CookRobot::connects()
{
}


void QtGu_CookRobot::drawQueue()
{
	auto i = _queue.begin();
	int number = 1;
	for (; i != _queue.end(); i++, number++) {
		_queueLabels.at(number - 1)->setText(QString::number(number) + ": " + (*i)->toString());
	}
	ui.groupBox_queue->setFixedHeight(number * 20);
}

void QtGu_CookRobot::on_pushButton_load_clicked() {
	_queue.load(QFileDialog::getOpenFileName(this, "Open File", "", "Json (*.json)"));
	drawQueue();
}

void QtGu_CookRobot::on_pushButton_dump_clicked() {
	_queue.dump(QFileDialog::getSaveFileName(this, "Save File", "", "Json (*.json)"));
}

void QtGu_CookRobot::on_pushButton_clear_clicked() {
	_queue.clear();
	drawQueue();
}
void QtGu_CookRobot::on_pushButton_addIngredient_clicked() {
	QueueItem* item = static_cast<QueueItem*>(new Ingredient);
	_queue.push(item);
	drawQueue();
}
void QtGu_CookRobot::on_pushButton_addOperation_clicked() {
	QueueItem* item = static_cast<QueueItem*>(new Operation);
	_queue.push(item);
	drawQueue();
}
void QtGu_CookRobot::on_item_clicked() {
	QPushButton* i = static_cast<QPushButton*>(sender());
	delete i;
}