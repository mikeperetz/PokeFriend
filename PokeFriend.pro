#-------------------------------------------------
#
# Project created by QtCreator 2015-12-04T23:03:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PokeFriend
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    pokelibrary.cpp \
    pokemon.cpp \
    move.cpp \
    ability.cpp \
    item.cpp \
    teampokemon.cpp \
    team.cpp \
    effect.cpp

HEADERS  += mainwindow.h \
    pokelibrary.h \
    pokemon.h \
    move.h \
    ability.h \
    item.h \
    teampokemon.h \
    team.h \
    effect.h

FORMS    += mainwindow.ui

DISTFILES += \
    pokemonlist.txt \
    stats.txt \
    usagestats.txt
