#ifndef SETTINGSDIALOGWINDOW_H
#define SETTINGSDIALOGWINDOW_H
#include <QDialog>
#include <vector>
#include "settingsbuttonbox.h"
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
    SettingsDialogWindow(QWidget *parent, SettingsButtonBox *btn,
                         std::vector<SettingsButtonBox *> *btnList,
                         std::vector<GroupTab*> &grpList);
    ~SettingsDialogWindow();

private slots:


    void on_buttonBox_clicked(QAbstractButton *button);

    void onStatusButtonClicked();

signals:
    void deviceGroupChanged(QString newGroupName, SettingsButtonBox *btn);

private:
    Ui::SettingsDialogWindow           *ui;
    DynamicBulbButton                      *deviceButton;
    SettingsButtonBox                  *deviceSettingsButton;
    std::vector<SettingsButtonBox*>    *buttonList;
    std::vector<GroupTab*>              groupList;
    QString                             stylesList[stylesAmount];



};

#endif // SETTINGSDIALOGWINDOW_H
