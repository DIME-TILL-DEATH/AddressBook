QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/clientmanager.cpp \
        src/contact.cpp \
        src/contactsmodel.cpp \
        src/contactsworker.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
# добавили базовый путь для поиска
QML_IMPORT_PATH += $$PWD/qml
QML2_IMPORT_PATH += $$PWD/qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/../shared/include

LIBS += -L$$PWD/../shared/lib -lNetworkLib

HEADERS += \
    include/clientmanager.h \
    include/contact.h \
    include/contactsmodel.h \
    include/contactsworker.h

