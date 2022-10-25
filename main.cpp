#include "mainwindow.h"
#include "logindialog.h"
#include "showwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow showWindow;
    showWindow.show();
    return a.exec();
}
