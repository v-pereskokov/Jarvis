#-------------------------------------------------
#
# Project created by QtCreator 2016-10-28T16:43:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI
TEMPLATE = app
macx {
QMAKE_CXXFLAGS += -std=c++14
INCLUDEPATH += "/opt/boost/include"
LIBS += -L/opt/boost/lib
LIBS += -lboost_system

}
LIBS += -L/usr/lib/x86_64-linux-gnu -lboost_system
LIBS += -lcurl
CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14
SOURCES += main.cpp\
        mainwindow.cpp \
    smartdevice.cpp \
    smartbulb.cpp \
    settingsdialogwindow.cpp \
    styles.cpp \
    smartbulbconfig.cpp \
    grouptab.cpp \
    settingsbuttonbox.cpp \
    widgetgridlayout.cpp \
    dynamicbulbbutton.cpp \
    adddevicewindow.cpp \
    ../../SmartHome/src/Devices.cpp \
    ../../SmartHome/src/SerialPort.cpp \
    ../../SmartHome/src/BluetoothHC05.cpp \
    ../../SmartHome/src/Bulb.cpp \
    ../../SmartHome/src/Device.cpp \
    ../../SmartHome/src/DevicesController.cpp \
    ../../SmartHome/src/Teapot.cpp \
    ../../SmartHome/src/Fan.cpp \
    ../../Jarvis/src/Command.cpp \
    ../../Jarvis/src/Jarvis.cpp \
    ../../Jarvis/src/Parser.cpp \
    ../../Jarvis/src/SpeechKit.cpp \
    ../../Jarvis/src/Transport.cpp \
    ../../Jarvis/src/Voice.cpp

HEADERS  += mainwindow.h \
    smartdevice.h \
    smartbulb.h \
    settingsdialogwindow.h \
    styles.h \
    smartbulbconfig.h \
    grouptab.h \
    settingsbuttonbox.h \
    widgetgridlayout.h \
    dynamicbulbbutton.h \
    adddevicewindow.h \
    ../../SmartHome/include/Devices/Devices.hpp \
    ../../SmartHome/include/SerialPort.hpp \
    ../../SmartHome/include/BluetoothHC05.hpp \
    ../../SmartHome/include/Devices/Bulb.hpp \
    ../../SmartHome/include/Devices/Device.hpp \
    ../../SmartHome/include/DevicesController.hpp \
    ../../SmartHome/include/Devices/Teapot.hpp \
    ../../SmartHome/include/Commands.hpp \
    ../../SmartHome/include/Mediator.hpp \
    ../../SmartHome/include/Devices/Fan.hpp \
    ../../Jarvis/include/Command.hpp \
    ../../Jarvis/include/Jarvis.hpp \
    ../../Jarvis/include/Parser.hpp \
    ../../Jarvis/include/SpeechKit.hpp \
    ../../Jarvis/include/Transport.hpp \
    ../../Jarvis/include/Voice.hpp


FORMS    += mainwindow.ui \
    settingsdialogwindow.ui \
    smartbulbconfig.ui \
    adddevicewindow.ui

RESOURCES += \
    res.qrc
