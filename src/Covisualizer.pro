QT       += core gui
QT       += network
QT       += charts

# Integration von OpenSSL-Bibliotheken unter dem angegeben Pfad
LIBS += -L$$OUT_PWD/../lib
-libcrypto-1_1-x64
-libssl-1_1-x64
-libcrypto.lib
-libssl.lib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    databank.cpp \
    datenbank.cpp \
    dbvorschau.cpp \
    laender.cpp \
    downloader.cpp \
    land.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    databank.h \
    datenbank.h \
    dbvorschau.h \
    laender.h \
    land.h \
    mainwindow.h \
    downloader.h


FORMS += \
    datenbank.ui \
    dbvorschau.ui \
    land.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressources.qrc

RC_ICONS = covisual.ico

DISTFILES +=

