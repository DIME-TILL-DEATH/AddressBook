QT -= gui
QT += core sql
CONFIG += C++11
TEMPLATE = lib

DEFINES += BUILD_TESTS

DESTDIR = $$PWD/../shared/lib

INCLUDEPATH += $$PWD/include

HEADERS += \
    include/Manipulator.h \
    include/Processor.h \
    include/Selector.h \
    include/connectionmanager.h \
    include/dbmapper.h \
    include/dbtypes.h \
    include/executor.h

SOURCES += \
    src/Manipulator.cpp \
    src/Processor.cpp \
    src/Selector.cpp \
    src/connectionmanager.cpp \
    src/executor.cpp

headers.path = $$PWD/../shared/include
headers.files = include/dbtypes.h \
                include/Processor.h

INSTALLS += headers
