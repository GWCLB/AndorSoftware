#include "andorsoftware.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AndorSoftware w;
	w.show();
	return a.exec();
}
