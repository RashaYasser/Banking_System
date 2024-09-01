cmake_minimum_required(VERSION 3.1)

project(Server LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network Widgets)

add_executable(Server
  main.cpp
  MyServer.h MyServer.cpp
  DataBaseManager.h DataBaseManager.cpp
  MyServerHandler.h MyServerHandler.cpp

  RequestHandler.h RequestHandler.cpp
  Signature.h Signature.cpp
  Encryption.h Encryption.cpp
  Memento.h Memento.cpp
)

target_link_libraries(Server Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::Widgets)

include(GNUInstallDirs)
install(TARGETS Server
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
