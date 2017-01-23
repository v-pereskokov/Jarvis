#include "adddevicewindow.h"
#include "ui_adddevicewindow.h"

AddDeviceWindow::AddDeviceWindow(QWidget *parent) :
QDialog(parent),
ui(new Ui::AddDeviceWindow), ui2{new Ui::Loading}
{
  ui2->setupUi(this);
  initMovie = new QMovie(":/images/init.gif");

}

void AddDeviceWindow::changeUI()
{
  ui2->initLabel->hide();
  ui->setupUi(this);

  QPushButton *tempBtn;
  QString stylesList[stylesAmount];
  setStyles(stylesList);
  for(size_t i = 0; i < avaliableDevices.size(); ++i)
    {
    std::string deviceBTName =  avaliableDevices[i].first;
    tempBtn = new QPushButton(QString::fromUtf8(deviceBTName.c_str()), ui->scrollAreaWidgetContents);
    tempBtn->setStyleSheet(stylesList[4]);
    ui->avaliableDevicesLayout->addWidget(tempBtn);
    connect(tempBtn, SIGNAL(clicked()), this, SLOT(getButtonName()));
    }

}

AddDeviceWindow::AddDeviceWindow(QWidget *parent,
                                 std::vector<SettingsButtonBox *> &btnList,
                                 std::vector<std::pair<std::string, std::string>> avaliableDevices)
: AddDeviceWindow{parent}
{


  this->avaliableDevices = avaliableDevices;
  buttonList = btnList;  

  //ui2->setupUi(this);
  ui2->initLabel->setMovie( initMovie);
  connect(initMovie, SIGNAL(finished()), this, SLOT(changeUI()));
  initMovie->start();
}


void AddDeviceWindow::getButtonName()
{
  QPushButton *button = (QPushButton*) sender();
  ui->deviceEdit->setText(button->text());
}

AddDeviceWindow::~AddDeviceWindow()
{
  delete ui;
  delete ui2;
}

bool AddDeviceWindow::checkName(const QString& name) const
{
  for(size_t i = 0; i < buttonList.size(); ++i)
    {
    SettingsButtonBox *button = buttonList[i];
    if(button->deviceButton->text() == name)
      return false;
    }
  return true;
}


bool AddDeviceWindow::checkBluetoothName(const QString& name) const
{
  for(size_t i = 0; i < buttonList.size(); ++i)
    {
    SettingsButtonBox *button = buttonList[i];
    if(button->deviceButton->getDeviceBluetoothName() == name)
      return false;
    }
  return true;
}

void AddDeviceWindow::on_buttonBox_clicked(QAbstractButton *button)
{
  if(ui->buttonBox->standardButton(button) == QDialogButtonBox::Apply)
    {
    if(ui->deviceEdit->text() == "None")
      {
      QMessageBox::information(this, QString{"warning"}, QString{"Choose devise from the right list."});
      return;
      }
    if(!checkName(ui->deviceNameEdit->text()))
      {
      QMessageBox::information(this, QString{"warning"}, QString{"Name is already used."});
      return;
      }
    
    if(!checkBluetoothName(ui->deviceEdit->text()))
      {
      QMessageBox::information(this, QString{"warning"}, QString{"Device is already added."});
      return;
      }
    
    
    if(ui->deviceNameEdit->text().isEmpty())
      {
      QMessageBox::information(this, QString{"warning"}, QString{"Enter device name."});
      return;
      }
    for (int i = 0; i < avaliableDevices.size(); ++i)
      {
      std::string temp = avaliableDevices[i].first;
      if(QString::fromUtf8(temp.c_str()) == ui->deviceEdit->text())
        {
        emit(newDevice(ui->deviceEdit->text(), avaliableDevices[i].second,
                       ui->deviceNameEdit->text(), ui->deviceGroupEdit->text()));
        break;
        }
      }
    this->close();
    }
}
