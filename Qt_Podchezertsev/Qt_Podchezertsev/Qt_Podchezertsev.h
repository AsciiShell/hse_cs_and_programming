#pragma once

#include <QtWidgets/QMainWindow>
#include "QStandardItemModel"
#include "QStandardItem"
#include "ui_Qt_Podchezertsev.h"
#include "Device.h"

class Qt_Podchezertsev : public QMainWindow
{
	Q_OBJECT

public:
	Qt_Podchezertsev(QWidget *parent = Q_NULLPTR);
public slots:
	void on_pushButton_device_clicked();
	void on_table_clicked(const QModelIndex &index);
private:
	void drawDevices();
	void drawConnectors();
	Ui::Qt_PodchezertsevClass ui;
	QVector<Device<int>> devices;
	int lastDeviceIndex;
};
