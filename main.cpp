#include "lvtorrent.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LvTorrent w;
    w.show();

    return a.exec();
}
