#-------------------------------------------------
#
# Project created by QtCreator 2016-10-28T16:43:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    smartdevice.cpp \
    smartbulb.cpp \
    settingsdialogwindow.cpp \
    dynamicbutton.cpp \
    styles.cpp \
    smartbulbconfig.cpp \
    widgetverticallayout.cpp \
    grouptab.cpp

HEADERS  += mainwindow.h \
    smartdevice.h \
    smartbulb.h \
    settingsdialogwindow.h \
    dynamicbutton.h \
    styles.h \
    smartbulbconfig.h \
    widgetverticallayout.h \
    grouptab.h

FORMS    += mainwindow.ui \
    settingsdialogwindow.ui \
    smartbulbconfig.ui

RESOURCES += \
    res.qrc
