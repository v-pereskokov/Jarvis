/********************************************************************************
** Form generated from reading UI file 'settingsdialogwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOGWINDOW_H
#define UI_SETTINGSDIALOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialogWindow
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QWidget *layoutWidget1;
    QVBoxLayout *vertNameLabelsLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *nameEdit;
    QLineEdit *GroupNameEdit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *statusLabel;
    QRadioButton *statusRadioButton;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout;
    QLabel *idLabel;
    QLabel *deviceTypelabel;

    void setupUi(QDialog *SettingsDialogWindow)
    {
        if (SettingsDialogWindow->objectName().isEmpty())
            SettingsDialogWindow->setObjectName(QStringLiteral("SettingsDialogWindow"));
        SettingsDialogWindow->setWindowModality(Qt::WindowModal);
        SettingsDialogWindow->resize(398, 333);
        SettingsDialogWindow->setModal(true);
        layoutWidget = new QWidget(SettingsDialogWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 280, 291, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        frame = new QFrame(SettingsDialogWindow);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(40, 40, 301, 181));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget1 = new QWidget(frame);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 111, 151));
        vertNameLabelsLayout = new QVBoxLayout(layoutWidget1);
        vertNameLabelsLayout->setObjectName(QStringLiteral("vertNameLabelsLayout"));
        vertNameLabelsLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        vertNameLabelsLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        vertNameLabelsLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        vertNameLabelsLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        vertNameLabelsLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        vertNameLabelsLayout->addWidget(label_5);

        layoutWidget2 = new QWidget(frame);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(150, 10, 127, 60));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        nameEdit = new QLineEdit(layoutWidget2);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setFont(font);

        verticalLayout_3->addWidget(nameEdit);

        GroupNameEdit = new QLineEdit(layoutWidget2);
        GroupNameEdit->setObjectName(QStringLiteral("GroupNameEdit"));
        GroupNameEdit->setFont(font);

        verticalLayout_3->addWidget(GroupNameEdit);

        layoutWidget3 = new QWidget(frame);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(150, 80, 52, 20));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        statusLabel = new QLabel(layoutWidget3);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setFont(font);

        horizontalLayout_2->addWidget(statusLabel);

        statusRadioButton = new QRadioButton(layoutWidget3);
        statusRadioButton->setObjectName(QStringLiteral("statusRadioButton"));
        statusRadioButton->setFont(font);

        horizontalLayout_2->addWidget(statusRadioButton);

        layoutWidget4 = new QWidget(frame);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(150, 100, 104, 61));
        verticalLayout = new QVBoxLayout(layoutWidget4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 5, 0, 0);
        idLabel = new QLabel(layoutWidget4);
        idLabel->setObjectName(QStringLiteral("idLabel"));
        idLabel->setFont(font);
        idLabel->setMargin(0);

        verticalLayout->addWidget(idLabel);

        deviceTypelabel = new QLabel(layoutWidget4);
        deviceTypelabel->setObjectName(QStringLiteral("deviceTypelabel"));
        deviceTypelabel->setFont(font);

        verticalLayout->addWidget(deviceTypelabel);

        frame->raise();
        layoutWidget->raise();

        retranslateUi(SettingsDialogWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialogWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialogWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsDialogWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialogWindow)
    {
        SettingsDialogWindow->setWindowTitle(QApplication::translate("SettingsDialogWindow", "Device Setiings", 0));
        label->setText(QApplication::translate("SettingsDialogWindow", "Device Name:", 0));
        label_2->setText(QApplication::translate("SettingsDialogWindow", "Group Name:", 0));
        label_3->setText(QApplication::translate("SettingsDialogWindow", "Device Status:", 0));
        label_4->setText(QApplication::translate("SettingsDialogWindow", "Device ID:", 0));
        label_5->setText(QApplication::translate("SettingsDialogWindow", "Device Type:", 0));
        nameEdit->setText(QApplication::translate("SettingsDialogWindow", "name", 0));
        GroupNameEdit->setText(QApplication::translate("SettingsDialogWindow", "name", 0));
        statusLabel->setText(QApplication::translate("SettingsDialogWindow", "OFF", 0));
        statusRadioButton->setText(QString());
        idLabel->setText(QApplication::translate("SettingsDialogWindow", "ID", 0));
        deviceTypelabel->setText(QApplication::translate("SettingsDialogWindow", "Smart Device", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialogWindow: public Ui_SettingsDialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOGWINDOW_H
