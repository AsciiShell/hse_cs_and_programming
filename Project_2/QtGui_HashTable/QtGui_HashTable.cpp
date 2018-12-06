// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "QtGui_HashTable.h"

QtGui_HashTable::QtGui_HashTable(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QRegExp int_exp("[0-9]*");
	ui.lineEdit_addItem_value->setValidator(new QRegExpValidator(int_exp, this));
	ui.lineEdit_getTop->setValidator(new QRegExpValidator(int_exp, this));
	connect(ui.tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(on_table_clicked(const QModelIndex &)));
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
	setEditLayout(false);
	setResetLayout(false);
	ui.label_editItem_key->setText("");
}
void QtGui_HashTable::drawTopN(size_t n)
{
	QStandardItemModel *model = new QStandardItemModel;
	QStandardItem *item;
	QStringList horizontalHeader;
	horizontalHeader.append("Key");
	horizontalHeader.append("Value");


	model->setHorizontalHeaderLabels(horizontalHeader);
	auto result = _counter.getTopN(n);
	int index = 0;
	for (auto i = result.begin(); i != result.end(); ++i, index++)
	{
		model->setItem(index, 0, new QStandardItem((*i).key));
		model->setItem(index, 1, new QStandardItem(QString::number((*i).count)));
	}

	ui.tableView->setModel(model);
	ui.tableView->resizeRowsToContents();
	ui.tableView->resizeColumnsToContents();
	setEditLayout(false);
	setResetLayout(true);
	ui.label_editItem_key->setText("");
}
void QtGui_HashTable::setEditLayout(bool display)
{
	ui.pushButton_editItem_remove->setEnabled(display);
}
void QtGui_HashTable::setResetLayout(bool display)
{
	ui.pushButton_reset->setEnabled(display);
}
void QtGui_HashTable::on_pushButton_addItem_clicked()
{
	size_t count = 1;
	if (!ui.lineEdit_addItem_value->text().isEmpty())
		count = ui.lineEdit_addItem_value->text().toInt();
	_counter.addKey(ui.lineEdit_addItem_key->text(), count);
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
	drawTopN(ui.lineEdit_getTop->text().toInt());
}

void QtGui_HashTable::on_pushButton_editItem_remove_clicked()
{
	_counter.remove(ui.label_editItem_key->text());
	drawTable();
}
void QtGui_HashTable::on_pushButton_reset_clicked()
{
	drawTable();
}
void QtGui_HashTable::on_pushButton_load_clicked()
{
	std::ifstream ifile;
	ifile.open(QFileDialog::getOpenFileName(this, "Open File", "", "Text (*.txt)").toStdString());
	_counter.clear();
	ifile >> _counter;
	ifile.close();
	drawTable();
}
void QtGui_HashTable::on_pushButton_save_clicked()
{
	std::ofstream ofile;
	ofile.open(QFileDialog::getSaveFileName(this, "Open File", "", "Text (*.txt)").toStdString());
	ofile << _counter;
	ofile.close();
}
void QtGui_HashTable::on_table_clicked(const QModelIndex &index)
{
	if (index.isValid()) {
		setEditLayout(true);
		ui.label_editItem_key->setText(ui.tableView->model()->data(ui.tableView->model()->index(index.row(), 0)).toString());		
	}
}