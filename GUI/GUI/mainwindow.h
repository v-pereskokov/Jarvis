#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollBar>
#include <QMessageBox>
#include <QMovie>
#include <vector>
#include "settingsbuttonbox.h"
#include "settingsdialogwindow.h"
#include "smartbulbconfig.h"
#include "grouptab.h"
#include "../../SmartHome/include/Devices/Devices.hpp"


namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  QString getDeviceTypeFromBluetoothName(QString deviceBluetooth);
  ~MainWindow();
  
  private slots:
  void     on_addButton_clicked();    // Слот-обработчик нажатия кнопки добавления
  void     deleteButtonBox(QString deviceName); // Слот-обработчик удаления кнопки
  void     slotOpenDeviceConfig();    // Слот окрывающий окно конфигурации устройства(кнопки)
  void     slotSettingsButtonCLicked(); // Слот открывающий окно настроек устройства
  void     onTabClicked();              // Слот обрабоки сворачивания групп устройств
  void     changeDeviceGroupTab(QString newGroupTabName, SettingsButtonBox *btn); //Слот изменения группы устройства
  void     on_addGroup_clicked();   // Слот добавления группы устройств
  void     on_deleteGroup_clicked(); // Слот удаления группы устройств вместе с устройствами
  void     addDevice(QString deviceBluetooth, QString deviceName, QString groupName); // Слот создания устройства
  void     on_toolPushButton_clicked();  // Слот сворачивания/разворачивания панели управления
  void     setButtonIcon(int frame);
  void     on_microphoneButton_clicked();
  
private:
  SettingsButtonBox*  createDynamicButton(const QString deviceBluetooth, const QString &buttonName,
                                          const QString groupName, QWidget *parent = 0);
  void             deleteDynamicButton(const QString &buttonName);
  GroupTab*        getGroupTab(QString tabName, bool createIfNotExist, QWidget *parent = 0);
  GroupTab*        createGroupTab(QString tabName, QWidget *parent = 0);
  
  
  QMovie         *microphoneMovie;
  Ui::MainWindow *ui;
  std::vector<SettingsButtonBox*> buttonList;
  std::vector<GroupTab*>       groupList;
  QString stylesList[stylesAmount];
  Jarvis::Devices::DeviceFactory *_factory
  
};

#endif // MAINWINDOW_H
