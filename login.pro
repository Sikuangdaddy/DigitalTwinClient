QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DAQ/DioPortUI.cpp \
    DAQ/simplegraph.cpp \
    daqconfigdialog.cpp \
    daqconfiglistitem.cpp \
    daqdatamanager.cpp \
    data.cpp \
    inletpipe.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    networkproxy.cpp \
    showwindow.cpp \
    tooltipwidget.cpp

HEADERS += \
    DAQ/DioPortUI.h \
    DAQ/WaveformGenerator.h \
    DAQ/bdaqctrl.h \
    DAQ/simplegraph.h \
    daqconfigdialog.h \
    daqconfiglistitem.h \
    daqdatamanager.h \
    data.h \
    inletpipe.h \
    logindialog.h \
    mainwindow.h \
    networkproxy.h \
    showwindow.h \
    tooltipwidget.h

FORMS += \
    daqconfigdialog.ui \
    logindialog.ui \
    mainwindow.ui \
    showwindow.ui

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ppt/ppt.qrc
