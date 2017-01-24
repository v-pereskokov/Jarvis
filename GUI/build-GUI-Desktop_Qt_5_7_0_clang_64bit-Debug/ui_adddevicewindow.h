/********************************************************************************
** Form generated from reading UI file 'adddevicewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDEVICEWINDOW_H
#define UI_ADDDEVICEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddDeviceWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *deviceLayout;
    QLabel *deviceLabel;
    QLineEdit *deviceEdit;
    QLabel *deviceNameLabel;
    QLineEdit *deviceNameEdit;
    QLabel *deviceGroupLabel;
    QLineEdit *deviceGroupEdit;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *avaliableDevicesLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *AddDeviceWindow)
    {
        if (AddDeviceWindow->objectName().isEmpty())
            AddDeviceWindow->setObjectName(QStringLiteral("AddDeviceWindow"));
        AddDeviceWindow->setWindowModality(Qt::WindowModal);
        AddDeviceWindow->resize(496, 300);
        AddDeviceWindow->setStyleSheet(QStringLiteral("background-color: #222;"));
        gridLayout = new QGridLayout(AddDeviceWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        deviceLayout = new QVBoxLayout();
        deviceLayout->setObjectName(QStringLiteral("deviceLayout"));
        deviceLabel = new QLabel(AddDeviceWindow);
        deviceLabel->setObjectName(QStringLiteral("deviceLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deviceLabel->sizePolicy().hasHeightForWidth());
        deviceLabel->setSizePolicy(sizePolicy);
        deviceLabel->setStyleSheet(QStringLiteral("color: #00FBF6;"));
        deviceLabel->setMargin(5);

        deviceLayout->addWidget(deviceLabel);

        deviceEdit = new QLineEdit(AddDeviceWindow);
        deviceEdit->setObjectName(QStringLiteral("deviceEdit"));
        deviceEdit->setStyleSheet(QLatin1String("background-color: #333;\n"
"color: #00FBF6;"));
        deviceEdit->setReadOnly(true);

        deviceLayout->addWidget(deviceEdit);

        deviceNameLabel = new QLabel(AddDeviceWindow);
        deviceNameLabel->setObjectName(QStringLiteral("deviceNameLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(deviceNameLabel->sizePolicy().hasHeightForWidth());
        deviceNameLabel->setSizePolicy(sizePolicy1);
        deviceNameLabel->setStyleSheet(QStringLiteral("color: #00FBF6;"));
        deviceNameLabel->setMargin(5);

        deviceLayout->addWidget(deviceNameLabel);

        deviceNameEdit = new QLineEdit(AddDeviceWindow);
        deviceNameEdit->setObjectName(QStringLiteral("deviceNameEdit"));
        deviceNameEdit->setStyleSheet(QLatin1String("background-color: #333;\n"
"color: #00FBF6;"));

        deviceLayout->addWidget(deviceNameEdit);

        deviceGroupLabel = new QLabel(AddDeviceWindow);
        deviceGroupLabel->setObjectName(QStringLiteral("deviceGroupLabel"));
        sizePolicy1.setHeightForWidth(deviceGroupLabel->sizePolicy().hasHeightForWidth());
        deviceGroupLabel->setSizePolicy(sizePolicy1);
        deviceGroupLabel->setStyleSheet(QStringLiteral("color: #00FBF6;"));
        deviceGroupLabel->setMargin(5);

        deviceLayout->addWidget(deviceGroupLabel);

        deviceGroupEdit = new QLineEdit(AddDeviceWindow);
        deviceGroupEdit->setObjectName(QStringLiteral("deviceGroupEdit"));
        deviceGroupEdit->setStyleSheet(QLatin1String("background-color: #333;\n"
"color: #00FBF6;"));

        deviceLayout->addWidget(deviceGroupEdit);


        gridLayout->addLayout(deviceLayout, 1, 2, 1, 1);

        buttonBox = new QDialogButtonBox(AddDeviceWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: #009E9B;\n"
"	border: none;\n"
"	font:  14px;\n"
"	color: #fff;\n"
"	max-width: 200px;\n"
"	min-width: 80px;\n"
"	min-height: 20px;\n"
"	margin: 5px;\n"
"	padding: 5px;\n"
"}\n"
"QPushButton:disabled {\n"
"	background-color: #989898;\n"
"	color: #fff;\n"
"}\n"
".QPushButton :hover{\n"
"	background-color: #61b7ff;\n"
"	color: #fff;\n"
"}\n"
"QPushButton:focus { \n"
"	background-color: #61b7ff;\n"
"	color: #fff;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: #54dff0;\n"
"	color: #fff;\n"
"}"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel);

        gridLayout->addWidget(buttonBox, 3, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 2, 1, 1);

        scrollArea = new QScrollArea(AddDeviceWindow);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 211, 280));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        avaliableDevicesLayout = new QVBoxLayout();
        avaliableDevicesLayout->setObjectName(QStringLiteral("avaliableDevicesLayout"));
        avaliableDevicesLayout->setSizeConstraint(QLayout::SetMaximumSize);
        avaliableDevicesLayout->setContentsMargins(-1, -1, 0, -1);

        verticalLayout_2->addLayout(avaliableDevicesLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 4, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        retranslateUi(AddDeviceWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddDeviceWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddDeviceWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddDeviceWindow);
    } // setupUi

    void retranslateUi(QDialog *AddDeviceWindow)
    {
        AddDeviceWindow->setWindowTitle(QApplication::translate("AddDeviceWindow", "Add New Device", 0));
        deviceLabel->setText(QApplication::translate("AddDeviceWindow", "Device ", 0));
        deviceEdit->setText(QApplication::translate("AddDeviceWindow", "None", 0));
        deviceNameLabel->setText(QApplication::translate("AddDeviceWindow", "Device Name", 0));
        deviceNameEdit->setText(QApplication::translate("AddDeviceWindow", "SmartDevice", 0));
        deviceGroupLabel->setText(QApplication::translate("AddDeviceWindow", "Device Group", 0));
        deviceGroupEdit->setText(QApplication::translate("AddDeviceWindow", "Main Group", 0));
    } // retranslateUi

};

namespace Ui {
    class AddDeviceWindow: public Ui_AddDeviceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDEVICEWINDOW_H
