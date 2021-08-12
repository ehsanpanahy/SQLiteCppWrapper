TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        database/databasehandler.cpp \
        main.cpp \
        sqlite3/sqlite3.c

HEADERS += \
    database/databasehandler.h \
    sqlite3/sqlite3.h \
    sqlite3/sqlite3ext.h
