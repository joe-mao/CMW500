#-------------------------------------------------
#
# Project created by QtCreator 2019-09-18T13:16:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CMW500
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    powermeasure.cpp \
    harmonictest.cpp \
    phasenoise.cpp \
    information.cpp \
    cmw500.cpp \
    powermeter.cpp \
    signalgenerator.cpp \
    signalanalyzer.cpp \
    global.cpp

HEADERS += \
        mainwindow.h \
    powermeasure.h \
    harmonictest.h \
    phasenoise.h \
    information.h \
    cmw500.h \
    powermeter.h \
    signalgenerator.h \
    signalanalyzer.h \
    global.h

FORMS += \
        mainwindow.ui \
    powermeasure.ui \
    harmonictest.ui \
    phasenoise.ui \
    information.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

win32: LIBS += -L$$PWD/include/ -lvisa32

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/include/visa32.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/include/libvisa32.a
