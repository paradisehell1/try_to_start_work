QT       += core gui core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    encryptyng_mask.cpp \
    main.cpp \
    saving_way.cpp \
    mainwindow.cpp \
    timer.cpp

HEADERS += \
    dialog.h \
    encryptyng_mask.h \
    mainwindow.h \
    saving_way.h \
    timer.h

FORMS += \
    dialog.ui \
    encryptyng_mask.ui \
    mainwindow.ui \
    saving_way.ui \
    timer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
