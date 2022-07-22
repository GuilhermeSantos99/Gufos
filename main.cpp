#include "textgufo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    textGufo w;
    w.show();
    return a.exec();
}
