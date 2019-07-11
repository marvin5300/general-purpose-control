#-------------------------------------------------
#
# Project created by QtCreator 2019-07-11T07:13:20
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = general-purpose-control
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

DESTDIR = bin
UI_DIR = build/ui
MOC_DIR = build/moc
RCC_DIR = build/rcc
unix:OBJECTS_DIR = build/o/unix
win32:OBJECTS_DIR = build/o/win32
macx:OBJECTS_DIR = build/o/mac


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/keithley_2000.h \
    src/keithley_2410.h \
    src/keithley_2xxx.h \
    src/mainwindow.h \
    src/measurement_device.h \
    src/rs232.h

SOURCES += \
    src/keithley_2000.cpp \
    src/keithley_2410.cpp \
    src/keithley_2xxx.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/measurement_device.cpp \
    src/rs232.cpp

FORMS += \
    src/keithley_2000.ui \
    src/keithley_2410.ui \
    src/mainwindow.ui
