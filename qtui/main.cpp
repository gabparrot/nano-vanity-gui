#include "vanitygui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vanityGui w;
    w.show();

    return a.exec();
}
