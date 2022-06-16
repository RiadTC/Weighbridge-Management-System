#-------------------------------------------------
#
# Project created by QtCreator 2014-12-15T08:52:28
#
#-------------------------------------------------

QT     += core gui sql printsupport help
QT     += widgets serialport svg qml

TARGET = Weighbridge
TEMPLATE = app

INCLUDEPATH += $$_PRO_FILE_PWD_

SOURCES += main.cpp\
        mainwindow.cpp \
    Setup/Init.cpp \
    Setup/Operators.cpp \
    Setup/SettingsDialog.cpp \
    Other/LoginDialog.cpp \
    Setup/Customers.cpp \
    Setup/CustomerDialog.cpp \
    Setup/Items.cpp \
    mainwindowsetup.cpp \
    mainwindowreports.cpp \
    Setup/PriceList.cpp \
    Other/WeightBill.cpp \
    mainwindowfile.cpp \
    Other/mydelegate.cpp \
    Other/mysearchmodel.cpp \
    Other/miscfunc.cpp \
    Other/lineedit.cpp \
    Other/mystringdelegate.cpp \
    mainhelp.cpp \
    Other/dialoglineedit.cpp \
    Setup/ItemDialog.cpp \
    Setup/OperatorDialog.cpp

HEADERS  += mainwindow.h \
    Setup/Init.h \
    Other/LoginDialog.h \
    Setup/SettingsDialog.h \
    Setup/Operators.h \
    Setup/Customers.h \
    Setup/CustomerDialog.h \
    Setup/PriceList.h \
    Other/WeightBill.h \
    Setup/Items.h \
    Other/mysearchmodel.h \
    Other/miscfunc.h \
    Other/lineedit.h \
    Other/mydelegate.h \
    Other/mystringdelegate.h \
    Other/dialoglineedit.h \
    Setup/ItemDialog.h \
    Setup/OperatorDialog.h

FORMS    += mainwindow.ui \
    Setup/Customers.ui \
    Setup/CustomerDialog.ui \
    Setup/ItemDialog.ui \
    Other/ProgressDialog.ui \
    Setup/PriceList.ui \
    Other/WeightBill.ui \
    Other/LoginDialog.ui \
    Other/ServerDialog.ui \
    Setup/OperatorDialog.ui \
    Setup/SettingsDialog.ui \
    Setup/indicator.ui \
    Other/noticedialog.ui



unix:LIBS += -L$$PWD/lib/ -llimereport
win32:LIBS += -L$$PWD/lib1/ -llimereport

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/


unix:LIBS += -L$$PWD/lib/ -lQtZint
win32:LIBS += -L$$PWD/lib1/ -lQtZint

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
