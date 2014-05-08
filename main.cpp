#include <QApplication>
#include <QSplashScreen>
#include <QtTest/qtest.h>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QSplashScreen *splash = new QSplashScreen;
//    splash->setPixmap(QPixmap(":/images/icon.png"));
//    splash->show();

    MainWindow mainWin;
//    QTest::qSleep(3000);
//    splash->finish(&mainWin);
    mainWin.show();
//    delete splash;
    return a.exec();
}
