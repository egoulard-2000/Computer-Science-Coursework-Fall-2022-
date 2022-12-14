include(gtest_dependency.pri)

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += console c++17
#CONFIG -= app_bundle
CONFIG += thread

SOURCES += \
        main.cpp \
        ../EduApp/bishoppiece.cpp \
        ../EduApp/chessboard.cpp \
        ../EduApp/chessmove.cpp \
        ../EduApp/chesspiece.cpp \
        ../EduApp/chessposition.cpp \
        ../EduApp/kingpiece.cpp \
        ../EduApp/knightpiece.cpp \
        ../EduApp/pawnpiece.cpp \
        ../EduApp/queenpiece.cpp \
        ../EduApp/rookpiece.cpp \
        tests.cpp

HEADERS += \
        ../EduApp/bishoppiece.h \
        ../EduApp/chessboard.h \
        ../EduApp/chessmove.h \
        ../EduApp/chesspiece.h \
        ../EduApp/chessposition.h \
        ../EduApp/kingpiece.h \
        ../EduApp/knightpiece.h \
        ../EduApp\pawnpiece.h \
        ../EduApp/queenpiece.h \
        ../EduApp/rookpiece.h

INCLUDEPATH += ../EduApp
