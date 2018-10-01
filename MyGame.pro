#-------------------------------------------------
#
# Project created by QtCreator 2015-10-23T16:31:24
#
#-------------------------------------------------

QT       += core gui \
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyGame
TEMPLATE = app


SOURCES += main.cpp \
    actor.cpp \
    bullet.cpp \
    enemy.cpp \
    gameplay.cpp \
    score.cpp

HEADERS  += \
    actor.h \
    bullet.h \
    enemy.h \
    gameplay.h \
    score.h

FORMS    +=

RESOURCES += \
    res.qrc
