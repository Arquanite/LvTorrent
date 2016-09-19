#-------------------------------------------------
#
# Project created by QtCreator 2016-08-25T13:48:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LvTorrent
TEMPLATE = app

LIBS += -L$$PWD/Libs/ -lboost_system
LIBS += -L$$PWD/Libs/ -ltorrent-rasterbar
DEPENDPATH += $$PWD/Libs

INCLUDEPATH  += UI\
                DataStructures\
                UI/Widgets\
                libtorrent\

SOURCES += main.cpp\
        UI/lvtorrent.cpp\
        session.cpp \
        DataStructures/basictorrentinfo.cpp \
        DataStructures/detailedtorrentinfo.cpp \
        UI/Widgets/toolbarbutton.cpp

HEADERS  += UI/lvtorrent.h\
            session.h \
            DataStructures/basictorrentinfo.h \
            DataStructures/detailedtorrentinfo.h \
            UI/Widgets/toolbarbutton.h

FORMS    += UI/lvtorrent.ui \

RESOURCES += \
    resources.qrc
