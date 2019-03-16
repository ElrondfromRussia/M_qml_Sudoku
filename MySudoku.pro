TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    sudokugamer.cpp \
    sudokumatrix.cpp \
    solver.cpp

RESOURCES += qml.qrc \
    img.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    sudokugamer.h \
    sudokumatrix.h \
    solver.h

DISTFILES += \
    myapp.rc \
    myapp.rc

win32: RC_FILE = myapp.rc
