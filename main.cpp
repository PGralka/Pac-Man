#include <QApplication>

#include "Window.h"

#define WIDTH 27 * 30
#define HEIGHT 30 * 30

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
	Window(WIDTH, HEIGHT);
	return QApplication::exec();
}
