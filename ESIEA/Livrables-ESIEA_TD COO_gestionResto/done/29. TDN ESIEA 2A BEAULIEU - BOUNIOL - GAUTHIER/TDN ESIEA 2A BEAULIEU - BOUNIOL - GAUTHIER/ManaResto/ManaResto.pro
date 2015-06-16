#-------------------------------------------------
#
# Project created by QtCreator 2015-04-23T17:54:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ManaResto
TEMPLATE = app


SOURCES += main.cpp\
    src/beverage.cpp \
    src/customer.cpp \
    src/dish.cpp \
    src/food.cpp \
    src/order.cpp \
    src/tools.cpp \
    neworderwindow.cpp \
    startwindow.cpp \
    newcustomerwindow.cpp \
    dishselectionwindow.cpp \
    commandcheckwindow.cpp \
    goodbyewindow.cpp \
    adminpanel.cpp

HEADERS  += \
    src/beverage.h \
    src/customer.h \
    src/dish.h \
    src/food.h \
    src/order.h \
    src/tools.h \
    neworderwindow.h \
    startwindow.h \
    newcustomerwindow.h \
    dishselectionwindow.h \
    commandcheckwindow.h \
    goodbyewindow.h \
    adminpanel.h

FORMS    += \
    neworderwindow.ui \
    startwindow.ui \
    newcustomerwindow.ui \
    dishselectionwindow.ui \
    commandcheckwindow.ui \
    goodbyewindow.ui \
    adminpanel.ui
