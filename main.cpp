#include "pranksoftware.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pranksoftware w;
    w.show();
    return a.exec();
}
