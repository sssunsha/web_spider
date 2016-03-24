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
    parsemanager.cpp \
    treenode.cpp \
    treemanager.cpp

HEADERS += \
    constant.h \
    networkmanager.h \
    manager.h \
    localmanager.h \
    parsemanager.h \
    treenode.h \
    treemanager.h

DISTFILES += \
    UC.txt

