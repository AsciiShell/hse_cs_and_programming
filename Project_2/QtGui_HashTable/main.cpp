#include "QtGui_HashTable.h"
#include <QtWidgets/QApplication>
#include "../Project_2/Counter.h"
int main(int argc, char *argv[])
{
	Counter<int> c;
	QApplication a(argc, argv);
	QtGui_HashTable w;
	w.show();
	return a.exec();
}
