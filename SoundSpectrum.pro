#-------------------------------------------------
#
# Project created by QtCreator 2016-01-02T20:53:59
#
#-------------------------------------------------

QWT_DIR =  c:\qwt-6.1.2\


QT       += core gui multimedia

INCLUDEPATH += $${PWD}\qwt\inc \
               $${PWD}\qfft\inc

DEPENDPATH += $${QWT_DIR}\lib

LIBS += $${PWD}\qwt.dll


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SoundSpectrum
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    spectrumwidget.cpp \
    audiostream.cpp \
    fftstream.cpp \
    qfft/sources/qcomplexnumber.cpp \
    qfft/sources/qfouriercalculator.cpp \
    qfft/sources/qfourierfixedcalculator.cpp \
    qfft/sources/qfouriertransformer.cpp \
    qfft/sources/qfouriervariablecalculator.cpp \
    qfft/sources/qwindowfunction.cpp \
    settings.cpp

HEADERS  += mainwindow.h \
    spectrumwidget.h \
    audiostream.h \
    fftstream.h \
    globals.h \
    qfft/headers/qcomplexnumber.h \
    qfft/headers/qfouriercalculator.h \
    qfft/headers/qfourierfixedcalculator.h \
    qfft/headers/qfouriertransformer.h \
    qfft/headers/qfouriervariablecalculator.h \
    qfft/headers/qwindowfunction.h \
    settings.h

FORMS    += mainwindow.ui

#CONFIG += qwt
