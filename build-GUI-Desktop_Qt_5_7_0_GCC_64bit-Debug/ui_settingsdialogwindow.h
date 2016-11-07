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
#include <QtWidgets/QGridLayout>
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
    QGridLayout *gridLayout;
    QVBoxLayout *vertNameLabelsLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout;
    QLabel *idLabel;
    QLabel *deviceTypelabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *statusLabel;
    QRadioButton *statusRadioButton;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *nameEdit;
    QLineEdit *GroupNameEdit;

    void setupUi(QDialog *SettingsDialogWindow)
    {
        if (SettingsDialogWindow->objectName().isEmpty())
            SettingsDialogWindow->setObjectName(QStringLiteral("SettingsDialogWindow"));
        SettingsDialogWindow->setWindowModality(Qt::WindowModal);
        SettingsDialogWindow->resize(421, 312);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingsDialogWindow->sizePolicy().hasHeightForWidth());
        SettingsDialogWindow->setSizePolicy(sizePolicy);
        SettingsDialogWindow->setStyleSheet(QStringLiteral("background-color: #222;"));
        SettingsDialogWindow->setSizeGripEnabled(false);
        SettingsDialogWindow->setModal(true);
        layoutWidget = new QWidget(SettingsDialogWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 250, 320, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        buttonBox = new QDialogButtonBox(layoutWidget);
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
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        frame = new QFrame(SettingsDialogWindow);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(40, 40, 298, 160));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        vertNameLabelsLayout = new QVBoxLayout();
        vertNameLabelsLayout->setObjectName(QStringLiteral("vertNameLabelsLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: #00FBF6;"));

        vertNameLabelsLayout->addWidget(label);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: #00FBF6;"));

        vertNameLabelsLayout->addWidget(label_2);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: #00FBF6;"));

        vertNameLabelsLayout->addWidget(label_3);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: #00FBF6;"));

        vertNameLabelsLayout->addWidget(label_4);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: #00FBF6;"));

        vertNameLabelsLayout->addWidget(label_5);


        gridLayout->addLayout(vertNameLabelsLayout, 0, 0, 3, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 5, -1, -1);
        idLabel = new QLabel(frame);
        idLabel->setObjectName(QStringLiteral("idLabel"));
        idLabel->setFont(font);
        idLabel->setStyleSheet(QStringLiteral("color: #00FBF6;"));
        idLabel->setMargin(0);

        verticalLayout->addWidget(idLabel);

        deviceTypelabel = new QLabel(frame);
        deviceTypelabel->setObjectName(QStringLiteral("deviceTypelabel"));
        deviceTypelabel->setFont(font);
        deviceTypelabel->setStyleSheet(QStringLiteral("color: #00FBF6;"));

        verticalLayout->addWidget(deviceTypelabel);


        gridLayout->addLayout(verticalLayout, 2, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        statusLabel = new QLabel(frame);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setFont(font);
        statusLabel->setStyleSheet(QLatin1String("color: #00FBF6;\n"
"background-color: #333;"));

        horizontalLayout_2->addWidget(statusLabel);

        statusRadioButton = new QRadioButton(frame);
        statusRadioButton->setObjectName(QStringLiteral("statusRadioButton"));
        statusRadioButton->setFont(font);
        statusRadioButton->setStyleSheet(QLatin1String("background-color: #333;\n"
"color: #00FBF6;"));

        horizontalLayout_2->addWidget(statusRadioButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        nameEdit = new QLineEdit(frame);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setFont(font);
        nameEdit->setStyleSheet(QLatin1String("background-color: #333;\n"
"color: #00FBF6;"));

        verticalLayout_3->addWidget(nameEdit);

        GroupNameEdit = new QLineEdit(frame);
        GroupNameEdit->setObjectName(QStringLiteral("GroupNameEdit"));
        GroupNameEdit->setFont(font);
        GroupNameEdit->setStyleSheet(QLatin1String("background-color: #333;\n"
"color: #00FBF6;"));

        verticalLayout_3->addWidget(GroupNameEdit);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

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
        idLabel->setText(QApplication::translate("SettingsDialogWindow", "ID", 0));
        deviceTypelabel->setText(QApplication::translate("SettingsDialogWindow", "Smart Device", 0));
        statusLabel->setText(QApplication::translate("SettingsDialogWindow", "OFF", 0));
        statusRadioButton->setText(QString());
        nameEdit->setText(QApplication::translate("SettingsDialogWindow", "name", 0));
        GroupNameEdit->setText(QApplication::translate("SettingsDialogWindow", "name", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialogWindow: public Ui_SettingsDialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOGWINDOW_H
