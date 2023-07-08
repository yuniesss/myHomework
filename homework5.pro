QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deck.cpp \
    fight.cpp \
    gamemap.cpp \
    main.cpp \
    monster.cpp \
    mybutton.cpp \
    mymap.cpp \
    player.cpp \
    widget.cpp

HEADERS += \
    deck.h \
    fight.h \
    gamemap.h \
    monster.h \
    mybutton.h \
    mymap.h \
    player.h \
    widget.h

FORMS += \
    fight.ui \
    mymap.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
