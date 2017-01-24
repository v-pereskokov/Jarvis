/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionJ_A_R_V_I_S_project;
    QAction *actionDevelopers;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayoutLeft;
    QSpacerItem *verticalSpacer_2;
    QPushButton *microphoneButton;
    QPushButton *toolPushButton;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *groupNameEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addGroup;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *deleteGroup;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menuBar;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(672, 422);
        MainWindow->setStyleSheet(QStringLiteral("background-color: #222;"));
        actionJ_A_R_V_I_S_project = new QAction(MainWindow);
        actionJ_A_R_V_I_S_project->setObjectName(QStringLiteral("actionJ_A_R_V_I_S_project"));
        actionJ_A_R_V_I_S_project->setCheckable(false);
        actionDevelopers = new QAction(MainWindow);
        actionDevelopers->setObjectName(QStringLiteral("actionDevelopers"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(300, 60));
        scrollArea->setMaximumSize(QSize(550, 16777215));
        scrollArea->setLayoutDirection(Qt::LeftToRight);
        scrollArea->setLineWidth(1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setEnabled(true);
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 298, 327));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        scrollAreaWidgetContents->setMaximumSize(QSize(300, 16777215));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayoutLeft = new QVBoxLayout();
        verticalLayoutLeft->setSpacing(6);
        verticalLayoutLeft->setObjectName(QStringLiteral("verticalLayoutLeft"));
        verticalLayoutLeft->setSizeConstraint(QLayout::SetMinimumSize);

        verticalLayout_2->addLayout(verticalLayoutLeft);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 3, 1);

        microphoneButton = new QPushButton(centralWidget);
        microphoneButton->setObjectName(QStringLiteral("microphoneButton"));
        microphoneButton->setMaximumSize(QSize(70, 70));
        microphoneButton->setStyleSheet(QLatin1String("QPushButton {  						\n"
"						border-radius: 50px;						\n"
"                        }"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/microphone.gif"), QSize(), QIcon::Normal, QIcon::Off);
        microphoneButton->setIcon(icon);
        microphoneButton->setIconSize(QSize(70, 70));

        gridLayout->addWidget(microphoneButton, 0, 3, 1, 1);

        toolPushButton = new QPushButton(centralWidget);
        toolPushButton->setObjectName(QStringLiteral("toolPushButton"));
        toolPushButton->setStyleSheet(QLatin1String("QPushButton {                         \n"
"                          text-align: left;\n"
"						background-color: #004A49;\n"
"                          background-repeat: none; \n"
"						 min-width: 70px; \n"
"                          min-height: 70px;\n"
"                          max-width: 70px; \n"
"                          max-height: 70px;\n"
"						border: #535353 1px solid;\n"
"						border-radius: 35px;\n"
"						align: rigth;\n"
"                        }\n"
"                        QPushButton:hover {\n"
"                           background-color: #2897ff;\n"
"                        }\n"
""));
        toolPushButton->setCheckable(true);
        toolPushButton->setFlat(true);

        gridLayout->addWidget(toolPushButton, 2, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setMouseTracking(false);
        addButton->setFlat(true);

        horizontalLayout_2->addWidget(addButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 25, -1, -1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: #00FBF6;"));

        horizontalLayout_4->addWidget(label_2);

        groupNameEdit = new QLineEdit(centralWidget);
        groupNameEdit->setObjectName(QStringLiteral("groupNameEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupNameEdit->sizePolicy().hasHeightForWidth());
        groupNameEdit->setSizePolicy(sizePolicy2);
        groupNameEdit->setMinimumSize(QSize(100, 0));
        groupNameEdit->setStyleSheet(QLatin1String("background-color: #333;\n"
"color: #00FBF6;"));
        groupNameEdit->setMaxLength(50);
        groupNameEdit->setFrame(true);

        horizontalLayout_4->addWidget(groupNameEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        addGroup = new QPushButton(centralWidget);
        addGroup->setObjectName(QStringLiteral("addGroup"));

        horizontalLayout_3->addWidget(addGroup);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        deleteGroup = new QPushButton(centralWidget);
        deleteGroup->setObjectName(QStringLiteral("deleteGroup"));

        horizontalLayout_3->addWidget(deleteGroup);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 5, 3, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 672, 19));
        menuBar->setStyleSheet(QLatin1String("QMenuBar {\n"
"color: #00FBF6;\n"
"background-color: #333;\n"
"}\n"
"\n"
"QMenuBar:hover {\n"
"color: #00FBF6;\n"
"background-color: #111;\n"
"}"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuAbout->setStyleSheet(QLatin1String("QMenu {\n"
"color: #00FBF6;\n"
"background-color: #333;\n"
"}\n"
"QMenu:hover {\n"
"color: #00FBF6;\n"
"background-color: #111;\n"
"}"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::BottomToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionJ_A_R_V_I_S_project);
        menuAbout->addAction(actionDevelopers);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "J.A.R.V.I.S.", 0));
        actionJ_A_R_V_I_S_project->setText(QApplication::translate("MainWindow", "J.A.R.V.I.S project", 0));
        actionDevelopers->setText(QApplication::translate("MainWindow", "Developers", 0));
        microphoneButton->setText(QString());
        toolPushButton->setText(QString());
#ifndef QT_NO_STATUSTIP
        addButton->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        addButton->setText(QApplication::translate("MainWindow", "Add device", 0));
        label_2->setText(QApplication::translate("MainWindow", "Enter group name", 0));
        groupNameEdit->setText(QApplication::translate("MainWindow", "Main Group", 0));
        addGroup->setText(QApplication::translate("MainWindow", "Add Group", 0));
        deleteGroup->setText(QApplication::translate("MainWindow", "Delete Group", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
