#include "controllcameraqt.h"
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	controllCameraQt w;
	w.show();
	return a.exec();
}
