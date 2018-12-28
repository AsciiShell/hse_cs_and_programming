// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "Qt_Podchezertsev.h"

Qt_Podchezertsev::Qt_Podchezertsev(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QRegExp int_exp("[0-9]*");
	ui.lineEdit_len->setValidator(new QRegExpValidator(int_exp, this));
	ui.lineEdit_id->setValidator(new QRegExpValidator(int_exp, this));

	lastDeviceIndex = -1;

	Device<int> d("One", 10);
	d.fillRandomConnector(10);
	Device<int> d2("Two", 10);
	d2.fillRandomConnector(10);
	Device<int> d3 = d + d2;
	devices.push_back(d);
	devices.push_back(d2);
	devices.push_back(d3);
	drawDevices();
	connect(ui.tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(on_table_clicked(const QModelIndex &)));
}

void Qt_Podchezertsev::drawDevices()
{
	QStandardItemModel *model = new QStandardItemModel;
	QStandardItem *item;
	QStringList horizontalHeader;
	horizontalHeader.append("Name");
	horizontalHeader.append("Size");


	model->setHorizontalHeaderLabels(horizontalHeader);
	int index = 0;
	for (auto item : devices)
	{
		model->setItem(index, 0, new QStandardItem(item.getName()));
		model->setItem(index, 1, new QStandardItem(QString::number(item.getCount())));
		index++;
	}

	ui.tableView->setModel(model);
	ui.tableView->resizeRowsToContents();
	ui.tableView->resizeColumnsToContents();
}
void Qt_Podchezertsev::drawConnectors()
{
	QStandardItemModel *model = new QStandardItemModel;
	QStandardItem *item;
	QStringList horizontalHeader;
	horizontalHeader.append("Id");
	horizontalHeader.append("Type");

	model->setHorizontalHeaderLabels(horizontalHeader);
	int index = 0;
	if (lastDeviceIndex >= 0 && lastDeviceIndex < devices.length())
		for (auto item : devices.at(lastDeviceIndex))
		{
			model->setItem(index, 0, new QStandardItem(QString::number(item->getId())));
			model->setItem(index, 1, new QStandardItem(item->getType() ? "Male" : "Female"));
			index++;
		}

	ui.tableView_2->setModel(model);
	ui.tableView_2->resizeRowsToContents();
	ui.tableView_2->resizeColumnsToContents();
}
void Qt_Podchezertsev::on_pushButton_device_clicked()
{
	Device<int> device(ui.lineEdit_name->text(), ui.lineEdit_len->text().toInt());
	device.fillRandomConnector(10);
	devices.push_back(device);
	drawDevices();
}
void Qt_Podchezertsev::on_table_clicked(const QModelIndex &index)
{
	if (index.isValid()) {
		lastDeviceIndex = index.row();
		drawConnectors();
	}
}