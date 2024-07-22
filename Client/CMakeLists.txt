cmake_minimum_required(VERSION 3.5)

project(BankingSystemClient VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    myclient.cpp
    myclient.h
    request.h
    createnewuserrequest.cpp
    createnewuserrequest.h
    deleteuserrequest.cpp
    deleteuserrequest.h
    loginrequest.cpp
    loginrequest.h
    getaccountnumberadminrequest.cpp
    getaccountnumberadminrequest.h
    getaccountnumberuserrequest.cpp
    getaccountnumberuserrequest.h
    maketransactionrequest.cpp
    maketransactionrequest.h
    transferamountrequest.cpp
    transferamountrequest.h
    updateuserrequest.cpp
    updateuserrequest.h
    viewaccountdetailsrequest.cpp
    viewaccountdetailsrequest.h
    viewbalancerequest.cpp
    viewbalancerequest.h
    viewbankdatabaserequest.cpp
    viewbankdatabaserequest.h
    viewtransactionhistoryrequest.cpp
    viewtransactionhistoryrequest.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(BankingSystemClient
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(BankingSystemClient SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(BankingSystemClient
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(BankingSystemClient PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.BankingSystemClient)
endif()
set_target_properties(BankingSystemClient PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS BankingSystemClient
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(BankingSystemClient)
endif()
