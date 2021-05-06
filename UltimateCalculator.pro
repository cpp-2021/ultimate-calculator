QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    src/Addition.cpp \
    src/Carre.cpp \
    src/Constante.cpp \
    src/Division.cpp \
    src/Inverse.cpp \
    src/Ln.cpp \
    src/Multiplication.cpp \
    src/Oppose.cpp \
    src/Puissance.cpp \
    src/RacineCarre.cpp \
    src/Soustraction.cpp \
    src/ValAbsolue.cpp

HEADERS += \
    include/Addition.h \
    include/Carre.h \
    include/Constante.h \
    include/Division.h \
    include/Expression.h \
    include/Inverse.h \
    include/Ln.h \
    include/Multiplication.h \
    include/Operation.h \
    include/Oppose.h \
    include/Puissance.h \
    include/RacineCarre.h \
    include/RootExpressionSingleton.h \
    include/Soustraction.h \
    include/ValAbsolue.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
