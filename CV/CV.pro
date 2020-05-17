#-------------------------------------------------
#
# Project created by QtCreator 2020-05-02T00:25:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CV
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
        cvitae.cpp

HEADERS += \
        cvitae.h

FORMS += \
        cvitae.ui

INCLUDEPATH += C:\opencv320\build\install\include
LIBS += -LC:\opencv320\build\install\x86\mingw\bin

LIBS += -lopencv_calib3d320
LIBS += -lopencv_core320
LIBS += -lopencv_features2d320
LIBS += -lopencv_flann320
LIBS += -lopencv_highgui320
LIBS += -lopencv_imgcodecs320
LIBS += -lopencv_imgproc320
LIBS += -lopencv_ml320
LIBS += -lopencv_objdetect320
LIBS += -lopencv_videoio320
