#ifndef LOADINGWINDOW_H
#define LOADINGWINDOW_H

#include <QWidget>
#include <QMovie>

namespace Ui {
class LoadingWindow;
}

class LoadingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingWindow(QWidget *parent = 0);
    ~LoadingWindow();

private:
    Ui::LoadingWindow *ui;
    QMovie            *initMovie;
};

#endif // LOADINGWINDOW_H
