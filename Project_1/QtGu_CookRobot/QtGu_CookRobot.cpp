// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "QtGu_CookRobot.h"

QtGu_CookRobot::QtGu_CookRobot(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	_queue.load("dump.json");

	_queueItems = QList<QPushButton*>();
	for (int i = 0; i < 100; i++)
	{
		QPushButton *label = new QPushButton(ui.groupBox_queue);
		label->setText("");
		label->setGeometry(QRect(10, 23 * (i + 1), 180, 23));
		_queueItems.push_back(label);
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
	connect(ui.pushButton_ingredientApply, SIGNAL(clicked()), this, SLOT(on_pushButton_apply()));
	connect(ui.pushButton_operationApply, SIGNAL(clicked()), this, SLOT(on_pushButton_apply()));
}


void QtGu_CookRobot::drawQueue()
{
	auto i = _queue.begin();
	int number = 1;
	for (; i != _queue.end(); i++, number++) {
		_queueItems.at(number - 1)->setText(QString::number(number) + ": " + (*i)->toString());
	}
	ui.groupBox_queue->setFixedHeight(number * 23);
	setEmptyLayout();
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
	QPushButton* senderObject = static_cast<QPushButton*>(sender());
	int number = 0;
	for each (auto it  in _queueItems)
	{
		if (it == senderObject)
			break;
		number++;
	}
	QueueItem* item = _queue.at(number);
	if (item->getKind() == QueueItem::ITEM_INGREDIENT)
		setIngredientLayout((Ingredient*)item);
	else
		setOperationLayout((Operation*)item);
}

void QtGu_CookRobot::on_pushButton_apply()
{
	if (_ingredient)
	{
		_ingredient->setName(ui.lineEdit_ingredientName->text());
		_ingredient->setCount(ui.lineEdit_ingredientCount->text().toInt());
		_ingredient->setMeasure(static_cast<Ingredient::Measure>(ui.comboBox_ingredientMeasure->currentIndex()));
	}
	else if(_operation)
	{
		_operation->setDuration(ui.lineEdit_operationDuration->text().toInt());
		_operation->setAction(static_cast<Operation::Action>(ui.comboBox_operationType->currentIndex()));
	}
	drawQueue();
}

void QtGu_CookRobot::setEmptyLayout()
{
	ui.groupBox_ingredient->setVisible(false);
	ui.groupBox_operation->setVisible(false);
}
void QtGu_CookRobot::setIngredientLayout(Ingredient* item)
{
	ui.groupBox_ingredient->setVisible(true);
	ui.groupBox_operation->setVisible(false);
	_ingredient = item;
	_operation = nullptr;
	ui.lineEdit_ingredientName->setText(_ingredient->getName());
	ui.lineEdit_ingredientCount->setText(QString::number(_ingredient->getCount()));
	ui.comboBox_ingredientMeasure->setCurrentIndex(_ingredient->getMeasure());
}
void QtGu_CookRobot::setOperationLayout(Operation* item)
{
	ui.groupBox_ingredient->setVisible(false);
	ui.groupBox_operation->setVisible(true);
	_ingredient = nullptr;
	_operation = item;
	ui.lineEdit_operationDuration->setText(QString::number(_operation->getDuration()));
	ui.comboBox_operationType->setCurrentIndex(_operation->getAction());
}