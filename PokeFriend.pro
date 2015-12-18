#-------------------------------------------------
#
# Project created by QtCreator 2015-12-04T23:03:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PokeFriend
TEMPLATE = app

CONFIG += c++11 \ console

QMAKE_CXXFLAGS += -Wno-sign-compare -Wno-unused-parameter


SOURCES += main.cpp\
        mainwindow.cpp \
    pokelibrary.cpp \
    pokemon.cpp \
    move.cpp \
    ability.cpp \
    item.cpp \
    teampokemon.cpp \
    team.cpp \
    effect.cpp \
    statspread.cpp \
    type.cpp \
    status.cpp \
    basestats.cpp \
    stats.cpp \
    nature.cpp \
    scene.cpp \
    decisiontree.cpp

HEADERS  += mainwindow.h \
    pokelibrary.h \
    pokemon.h \
    move.h \
    ability.h \
    item.h \
    teampokemon.h \
    team.h \
    effect.h \
    statspread.h \
    type.h \
    status.h \
    basestats.h \
    stats.h \
    nature.h \
    scene.h \
    decisiontree.h

FORMS    +=

DISTFILES += \
    pokemonlist.txt \
    stats.txt \
    usagestats.txt \
    movelist.txt \
    MainForm.ui.qml \
    Main.qml \
    pokefriendlogo.png
