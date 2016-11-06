/********************************************************************************
** Form generated from reading UI file 'smartbulbconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTBULBCONFIG_H
#define UI_SMARTBULBCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmartBulbConfig
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *bulbName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *statusLabel;
    QCheckBox *statusCheckBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *brightnessSlider;
    QLCDNumber *lcdNumber;
    QPushButton *bulbImage;

    void setupUi(QDialog *SmartBulbConfig)
    {
        if (SmartBulbConfig->objectName().isEmpty())
            SmartBulbConfig->setObjectName(QStringLiteral("SmartBulbConfig"));
        SmartBulbConfig->resize(400, 276);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SmartBulbConfig->sizePolicy().hasHeightForWidth());
        SmartBulbConfig->setSizePolicy(sizePolicy);
        SmartBulbConfig->setSizeGripEnabled(false);
        SmartBulbConfig->setModal(true);
        buttonBox = new QDialogButtonBox(SmartBulbConfig);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 220, 341, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(SmartBulbConfig);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 251, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(11);
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        bulbName = new QLabel(layoutWidget);
        bulbName->setObjectName(QStringLiteral("bulbName"));
        bulbName->setFont(font);

        horizontalLayout_2->addWidget(bulbName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        statusLabel = new QLabel(layoutWidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setFont(font);

        horizontalLayout_3->addWidget(statusLabel);

        statusCheckBox = new QCheckBox(layoutWidget);
        statusCheckBox->setObjectName(QStringLiteral("statusCheckBox"));
        statusCheckBox->setFont(font);

        horizontalLayout_3->addWidget(statusCheckBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        brightnessSlider = new QSlider(layoutWidget);
        brightnessSlider->setObjectName(QStringLiteral("brightnessSlider"));
        brightnessSlider->setMinimum(1);
        brightnessSlider->setMaximum(100);
        brightnessSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(brightnessSlider);

        lcdNumber = new QLCDNumber(layoutWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setFont(font);
        lcdNumber->setStyleSheet(QLatin1String("color:rgb(0, 197, 0);\n"
"\n"
"border:none;\n"
"\n"
""));
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setFrameShadow(QFrame::Plain);
        lcdNumber->setLineWidth(0);
        lcdNumber->setDigitCount(3);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(lcdNumber);


        verticalLayout->addLayout(horizontalLayout);

        bulbImage = new QPushButton(SmartBulbConfig);
        bulbImage->setObjectName(QStringLiteral("bulbImage"));
        bulbImage->setGeometry(QRect(290, 50, 91, 91));
        bulbImage->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/bulbOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        bulbImage->setIcon(icon);
        bulbImage->setIconSize(QSize(91, 91));
        bulbImage->setFlat(true);

        retranslateUi(SmartBulbConfig);
        QObject::connect(buttonBox, SIGNAL(accepted()), SmartBulbConfig, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SmartBulbConfig, SLOT(reject()));

        QMetaObject::connectSlotsByName(SmartBulbConfig);
    } // setupUi

    void retranslateUi(QDialog *SmartBulbConfig)
    {
        SmartBulbConfig->setWindowTitle(QApplication::translate("SmartBulbConfig", "Bulb Configuration", 0));
        label_2->setText(QApplication::translate("SmartBulbConfig", "Bulb Name: ", 0));
        bulbName->setText(QApplication::translate("SmartBulbConfig", "Smart Bulb", 0));
        label_3->setText(QApplication::translate("SmartBulbConfig", "Status:               ", 0));
        statusLabel->setText(QApplication::translate("SmartBulbConfig", "OFF", 0));
        statusCheckBox->setText(QString());
        label->setText(QApplication::translate("SmartBulbConfig", "Brightness: ", 0));
        bulbImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SmartBulbConfig: public Ui_SmartBulbConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTBULBCONFIG_H
