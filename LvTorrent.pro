#-------------------------------------------------
#
# Project created by QtCreator 2016-08-25T13:48:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LvTorrent
TEMPLATE = app

LIBS += -LLIBs -lboost_system

INCLUDEPATH  += UI\
                DataStructures\
                Widgets\
                libtorrent\

SOURCES += main.cpp\
        UI/lvtorrent.cpp\
        session.cpp \
        DataStructures/basictorrentinfo.cpp \
        DataStructures/detailedtorrentinfo.cpp

HEADERS  += UI/lvtorrent.h\
            session.h \
            DataStructures/basictorrentinfo.h \
            DataStructures/detailedtorrentinfo.h

FORMS    += UI/lvtorrent.ui
