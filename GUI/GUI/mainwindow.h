#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollBar>
#include <QMessageBox>
#include <vector>
#include "settingsdialogwindow.h"
#include "smartbulbconfig.h"
#include "grouptab.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool checkName(const QString &name) const;

private slots:
    void on_addButton_clicked();    // Слот-обработчик нажатия кнопки добавления
    void on_deleteButton_clicked(); // Слот-обработчик нажатия кнопки удаления
    void slotGetButtonName();       // Слот для получения имени нажатой динамической кнопки
    void slotOpenDeviceConfig();    // Слот окрывающий окно настроек устройства(кнопки)

    void on_settingsButton_clicked();
    void on_lineEdit_textChanged(const QString &str);

    void onTabClicked();
    void changeDeviceGroupTab(QString newGroupTabName, DynamicButton *btn);
    void on_addGroup_clicked();
    void on_deleteGroup_clicked();

private:
    DynamicButton* createDynamicButton(const QString &buttonName, const QString groupName, QWidget *parent = 0);
    void           deleteDynamicButton(const QString &buttonName);
    GroupTab*      getGroupTab(QString tabName, bool createIfNotExist, QWidget *parent = 0);
    GroupTab*      createGroupTab(QString tabName, QWidget *parent = 0);


    Ui::MainWindow *ui;
    std::vector<DynamicButton*> buttonList;
    std::vector<GroupTab*>       groupList;
    QString stylesList[stylesAmount];


};

#endif // MAINWINDOW_H
