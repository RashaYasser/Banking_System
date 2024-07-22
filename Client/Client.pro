QT       += core gui
QT +=network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CreateNewUserRequest.cpp \
    DeleteUserRequest.cpp \
    GetAccountNumberAdminRequest.cpp \
    GetAccountNumberUserRequest.cpp \
    LoginRequest.cpp \
    MakeTransactionRequest.cpp \
    MyClient.cpp \
    Request.cpp \
    RequestValidator.cpp \
    ResponseHandler.cpp \
    TransferAmountRequest.cpp \
    UpdateUserRequest.cpp \
    ViewAccountDetailsRequest.cpp \
    ViewBalanceRequest.cpp \
    ViewBankDatabaseRequest.cpp \
    ViewTransactionHistoryRequest.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    CreateNewUserRequest.h \
    DeleteUserRequest.h \
    GetAccountNumberAdminRequest.h \
    GetAccountNumberUserRequest.h \
    LoginRequest.h \
    MakeTransactionRequest.h \
    MyClient.h \
    Request.h \
    RequestValidator.h \
    ResponseHandler.h \
    TransferAmountRequest.h \
    UpdateUserRequest.h \
    ViewAccountDetailsRequest.h \
    ViewBalanceRequest.h \
    ViewBankDatabaseRequest.h \
    ViewTransactionHistoryRequest.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
