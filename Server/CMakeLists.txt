cmake_minimum_required(VERSION 3.14)

project(Server LANGUAGES CXX)

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