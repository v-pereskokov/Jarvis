/********************************************************************************
** Form generated from reading UI file 'init.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INIT_H
#define UI_INIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Loading
{
public:
    QLabel *initLabel;

    void setupUi(QWidget *Loading)
    {
        if (Loading->objectName().isEmpty())
            Loading->setObjectName(QStringLiteral("Loading"));
        Loading->resize(640, 400);
        initLabel = new QLabel(Loading);
        initLabel->setObjectName(QStringLiteral("initLabel"));
        initLabel->setGeometry(QRect(0, 0, 640, 400));

        retranslateUi(Loading);

        QMetaObject::connectSlotsByName(Loading);
    } // setupUi

    void retranslateUi(QWidget *Loading)
    {
        Loading->setWindowTitle(QApplication::translate("Loading", "Loading", 0));
        initLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Loading: public Ui_Loading {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INIT_H
