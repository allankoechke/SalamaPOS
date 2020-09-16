QT += quick widgets charts sql

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
        cpp/databaseinterface.cpp \
        cpp/main.cpp \
        cpp/models/checkoutitems.cpp \
        cpp/models/checkoutitemsmodel.cpp \
        cpp/models/completer.cpp \
        cpp/models/completermodel.cpp \
        cpp/models/saleitems.cpp \
        cpp/models/saleitemsmodel.cpp \
        cpp/models/stockitems.cpp \
        cpp/models/stockitemsmodel.cpp \
        cpp/models/useraccounts.cpp \
        cpp/models/useraccountsmodel.cpp \
        cpp/qmlinterface.cpp \
        cpp/serialportinterface.cpp \
        cpp/webapiinterface.cpp \
        cpp/websocketsinterface.cpp

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
    cpp/databaseinterface.h \
    cpp/models/checkoutitems.h \
    cpp/models/checkoutitemsmodel.h \
    cpp/models/completer.h \
    cpp/models/completermodel.h \
    cpp/models/saleitems.h \
    cpp/models/saleitemsmodel.h \
    cpp/models/stockitems.h \
    cpp/models/stockitemsmodel.h \
    cpp/models/useraccounts.h \
    cpp/models/useraccountsmodel.h \
    cpp/qmlinterface.h \
    cpp/serialportinterface.h \
    cpp/webapiinterface.h \
    cpp/websocketsinterface.h

DISTFILES +=
