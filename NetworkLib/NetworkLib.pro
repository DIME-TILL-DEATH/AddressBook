QT += core

CONFIG += C++11

HEADERS += \
    include/connectionargumentsparser.h \
    include/networktypes.h \
    include/package.h

SOURCES += \
    src/connectionargumentsparser.cpp \
    src/package.cpp

INCLUDEPATH += include

TEMPLATE = lib

DESTDIR = $$PWD/../shared/lib

headers.path = ../shared/include
headers.files = include/connectionargumentsparser.h \
                include/networktypes.h \
                include/package.h

INSTALLS += headers
