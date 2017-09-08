#include "mainwindow.h"
#include <QApplication>
#include "globaldef.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    LOADQSS(":/qss/qss/style.qss");

    a.setFont(QFont("ZYSong18"));
    return a.exec();
}
