QT += core network
QT -= gui

TARGET = web_spider
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    networkmanager.cpp \
    manager.cpp \
    localmanager.cpp \
    parsemanager.cpp

HEADERS += \
    constant.h \
    networkmanager.h \
    manager.h \
    localmanager.h \
    parsemanager.h

DISTFILES += \
    UC.txt

