QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CRWin
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    activatorwindow.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    activatorwindow.h
