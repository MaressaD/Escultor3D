#include "mainwindow.h"
#include "sculptor.h"
#include <QApplication>
#include <fstream>
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    Sculptor trono(10,10,10);
    trono.setColor(0,0,1.0,1.0);
    trono.putBox(0,9,0,9,0,9);
    trono.cutBox(1,8,1,9,1,9);
    trono.writeOFF("trono.off");

}
