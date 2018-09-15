QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialPortWriterGUI
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS



SOURCES += \
        main.cpp \
        mainwindow.cpp \
        xfindserialdevice.cpp \
        xwritetoserialdevice.cpp

HEADERS += \
        mainwindow.h \
        xfindserialdevice.h \
        xwritetoserialdevice.h

FORMS += \
        mainwindow.ui
