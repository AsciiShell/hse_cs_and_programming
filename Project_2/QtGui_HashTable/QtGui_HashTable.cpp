#include "QtGui_HashTable.h"

QtGui_HashTable::QtGui_HashTable(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QRegExp int_exp("[0-9]*");
	ui.lineEdit_addItem_value->setValidator(new QRegExpValidator(int_exp, this));
	ui.lineEdit_editItem_value->setValidator(new QRegExpValidator(int_exp, this));
	ui.lineEdit_getTop->setValidator(new QRegExpValidator(int_exp, this));
	connect(ui.tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
	_counter.addKey("Ivanov");
	_counter.addKey("Петров");


	drawTable();
}

void QtGui_HashTable::drawTable()
{
	QStandardItemModel *model = new QStandardItemModel;
	QStandardItem *item;
	QStringList horizontalHeader;
	horizontalHeader.append("Key");
	horizontalHeader.append("Value");


	model->setHorizontalHeaderLabels(horizontalHeader);
	int index = 0;
	for (auto i = _counter.begin(); i != _counter.end(); ++i, index++)
	{
		model->setItem(index, 0, new QStandardItem(i.getKey()));
		model->setItem(index, 1, new QStandardItem(QString::number(i.getValue())));
	}

	ui.tableView->setModel(model);
	ui.tableView->resizeRowsToContents();
	ui.tableView->resizeColumnsToContents();
}
void QtGui_HashTable::setEditLayout(bool display)
{
	ui.verticalLayout_editItem->setEnabled(display);
}
void QtGui_HashTable::on_pushButton_addItem_clicked()
{
	_counter.addKey(ui.lineEdit_addItem_key->text(), ui.lineEdit_addItem_value->text().toInt());
	drawTable();
}
void QtGui_HashTable::on_pushButton_findKey_clicked()
{
	QString key = ui.lineEdit_findItem->text();
	if (_counter.isIn(key)) {
		ui.label_findItem_count->setText(QApplication::translate("QtGui_HashTableClass", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276: ", Q_NULLPTR) + QString::number(_counter[key]));
	}
	else {
		ui.label_findItem_count->setText(QApplication::translate("QtGui_HashTableClass", "\320\235\320\265 \320\275\320\260\320\271\320\264\320\265\320\275\320\276", Q_NULLPTR));
	}
}
void QtGui_HashTable::on_pushButton_clear_clicked()
{
	_counter.clear();
	drawTable();
}
void QtGui_HashTable::on_pushButton_getTop_clicked()
{
}
void QtGui_HashTable::on_pushButton_editItem_save_clicked()
{
}
void QtGui_HashTable::on_pushButton_editItem_remove_clicked()
{
}
void QtGui_HashTable::on_table_clicked(const QModelIndex &index)
{
	if (index.isValid()) {
		QString cellText = index.data().toString();
	}
}