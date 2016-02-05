#-------------------------------------------------
#
# Project created by QtCreator 2015-03-09T09:23:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThreadTest2
TEMPLATE = app


SOURCES += main.cpp\
        main_dialog.cpp \
    my_thread.cpp \
    mypicbox.cpp

HEADERS  += main_dialog.h \
    my_thread.h \
    mypicbox.h

FORMS    += maindialog.ui \
    mypicbox.ui
