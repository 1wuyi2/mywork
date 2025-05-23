QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    c4.cpp \
    chosemap.cpp \
    enemy.cpp \
    floor.cpp \
    game.cpp \
    lose.cpp \
    main.cpp \
    player.cpp \
    weapon.cpp \
    win.cpp

HEADERS += \
    bullet.h \
    c4.h \
    chosemap.h \
    enemy.h \
    floor.h \
    game.h \
    lose.h \
    player.h \
    weapon.h \
    win.h

FORMS += \
    chosemap.ui \
    game.ui \
    lose.ui \
    win.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Sounds.qrc \
    resource.qrc
QT += core gui multimedia
