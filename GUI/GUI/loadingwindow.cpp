#include "loadingwindow.h"
#include "ui_loadingwindow.h"

LoadingWindow::LoadingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadingWindow)
{
    ui->setupUi(this);
    initMovie = new QMovie(":/images/init.gif");
    ui->loadingLabel->setMovie(initMovie);
    connect(initMovie, SIGNAL(finished()), this, SLOT(close()));
    initMovie->start();
}

LoadingWindow::~LoadingWindow()
{
    delete ui;
}
