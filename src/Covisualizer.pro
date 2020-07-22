QT       += core gui
QT       += network
QT       += charts

# Integration von OpenSSL-Bibliotheken unter dem angegeben Pfad
LIBS += -L$$OUT_PWD/../lib
-libcrypto-1_1-x64
-libssl-1_1-x64

message($$_PRO_FILE_PWD_)
message($$_PRO_FILE_)


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
    main.cpp \
    albanien.cpp \
    andorra.cpp \
    belgien.cpp \
    bulgarien.cpp \
    daenemark.cpp \
    deutschland.cpp \
    estland.cpp \
    finnland.cpp \
    frankreich.cpp \
    griechenland.cpp \
    grossbritannien.cpp \
    irland.cpp \
    island.cpp \
    italien.cpp \
    kosovo.cpp \
    kroatien.cpp \
    lettland.cpp \
    litauen.cpp \
    mainwindow.cpp \
    mazedonien.cpp \
    moldawien.cpp \
    montenegro.cpp \
    niederlande.cpp \
    norwegen.cpp \
    oesterreich.cpp \
    polen.cpp \
    portugal.cpp \
    rumanien.cpp \
    schweden.cpp \
    schweiz.cpp \
    serbien.cpp \
    slowakei.cpp \
    slowenien.cpp \
    spanien.cpp \
    tschechien.cpp \
    ukraine.cpp \
    ungarn.cpp \
    weissrussland.cpp

HEADERS += \
    databank.h \
    datenbank.h \
    dbvorschau.h \
    albanien.h \
    andorra.h \
    belgien.h \
    bulgarien.h \
    daenemark.h \
    deutschland.h \
    estland.h \
    finnland.h \
    frankreich.h \
    griechenland.h \
    grossbritannien.h \
    irland.h \
    island.h \
    italien.h \
    kosovo.h \
    kroatien.h \
    laender.h \
    lettland.h \
    litauen.h \
    mainwindow.h \
    mazedonien.h \
    moldawien.h \
    montenegro.h \
    niederlande.h \
    norwegen.h \
    oesterreich.h \
    polen.h \
    portugal.h \
    rumanien.h \
    schweden.h \
    schweiz.h \
    serbien.h \
    slowakei.h \
    slowenien.h \
    spanien.h \
    tschechien.h \
    ukraine.h \
    ungarn.h \
    weissrussland.h \
    downloader.h


FORMS += \
    datenbank.ui \
    dbvorschau.ui \
    albanien.ui \
    andorra.ui \
    belgien.ui \
    bulgarien.ui \
    daenemark.ui \
    deutschland.ui \
    estland.ui \
    finnland.ui \
    frankreich.ui \
    griechenland.ui \
    grossbritannien.ui \
    irland.ui \
    island.ui \
    italien.ui \
    kosovo.ui \
    kroatien.ui \
    lettland.ui \
    litauen.ui \
    mainwindow.ui \
    mazedonien.ui \
    moldawien.ui \
    montenegro.ui \
    niederlande.ui \
    norwegen.ui \
    oesterreich.ui \
    polen.ui \
    portugal.ui \
    rumanien.ui \
    schweden.ui \
    schweiz.ui \
    serbien.ui \
    slowakei.ui \
    slowenien.ui \
    spanien.ui \
    tschechien.ui \
    ukraine.ui \
    ungarn.ui \
    weissrussland.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressources.qrc

DISTFILES +=


DISTFILES +=
