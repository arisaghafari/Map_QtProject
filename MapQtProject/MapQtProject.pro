QT += core gui qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#lessThan(QT_MAJOR_VERSION, 5.5):QT += declarative

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        locationtable.cpp \
        main.cpp \
        mainwindow.cpp \
        mysqlpass.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =


# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    locationtable.h \
    mainwindow.h \
    mysqlpass.h

CONFIG += qmltypes
QML_IMPORT_NAME = io.qt.examples.backend
QML_IMPORT_MAJOR_VERSION = 1

FORMS += \
    locationtable.ui \
    mainwindow.ui \
    mysqlpass.ui

#QT += declarative
QT += quickwidgets

QT += sql
QT += widgets

#LIBS += -L'/home/arisa/Desktop/Qt5.15.2-20211024T080546Z-001/Qt5.15.2/lib'
#LIBS += -llibmysql
LIBS += -lmysqlcppconn
INCLUDEPATH += -I/usr/share/doc/libmysqlcppconn-dev
LIBS        += -lGL
#unix:LIBS += -lpq
win32:LIBS += libpqdll.lib
