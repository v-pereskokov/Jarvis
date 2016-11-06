#ifndef SETTINGSDIALOGWINDOW_H
#define SETTINGSDIALOGWINDOW_H
#include <QDialog>
#include <vector>
#include "dynamicbutton.h"
#include "grouptab.h"
#include "styles.h"

namespace Ui {
class SettingsDialogWindow;
}

class SettingsDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialogWindow(QWidget *parent = 0);
    SettingsDialogWindow(QWidget *parent, DynamicButton *btn,
                         const std::vector<DynamicButton*> &btnList,
                         std::vector<GroupTab*> &grpList);
    ~SettingsDialogWindow();

private slots:


    void on_buttonBox_clicked(QAbstractButton *button);

    void on_statusRadioButton_clicked();

signals:
    void deviceGroupChanged(QString newGroupName, DynamicButton *btn);

private:
    Ui::SettingsDialogWindow    *ui;
    DynamicButton               *deviceButton;
    std::vector<DynamicButton*>  buttonList;
    std::vector<GroupTab*>       groupList;
    QString                      stylesList[stylesAmount];



};

#endif // SETTINGSDIALOGWINDOW_H
