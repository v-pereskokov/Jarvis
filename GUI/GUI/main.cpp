#include "mainwindow.h"
#include <QApplication>
#include "smartdevice.h"
#include  <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
