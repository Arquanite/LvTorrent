#-------------------------------------------------
#
# Project created by QtCreator 2016-08-25T13:48:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LvTorrent
TEMPLATE = app


SOURCES += main.cpp\
        lvtorrent.cpp\
    session.cpp \
    basictorrentinfo.cpp \
    detailedtorrentinfo.cpp

HEADERS  += lvtorrent.h\
    session.h \
    basictorrentinfo.h \
    detailedtorrentinfo.h

FORMS    += lvtorrent.ui
