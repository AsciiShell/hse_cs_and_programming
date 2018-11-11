#include "QtGu_CookRobot.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGu_CookRobot w;
	w.show();
	return a.exec();
}
