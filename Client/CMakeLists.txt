# Set the minimum required version of CMake to ensure compatibility with the features used
cmake_minimum_required(VERSION 3.14)  # Qt 6 often requires at least version 3.14

# Define the source files for the library target
set(LIB_SOURCES
    mainwindow.cpp
    MyClient.cpp
    CreateNewUserRequest.cpp
    DeleteUserRequest.cpp
    GetAccountNumberAdminRequest.cpp
    GetAccountNumberUserRequest.cpp
    LoginRequest.cpp
    MakeTransactionRequest.cpp
    RequestValidator.cpp
    ResponseHandler.cpp
    Signature.cpp
    TransferAmountRequest.cpp
    UpdateUserRequest.cpp
    ViewAccountDetailsRequest.cpp
    ViewBalanceRequest.cpp
    ViewBankDatabaseRequest.cpp
    ViewTransactionHistoryRequest.cpp
    Encryption.cpp
)

# Define the source files for the executable target
set(SOURCES main.cpp)

# Define the header files that require MOC processing
set(HEADERS
    mainwindow.h
    MyClient.h
    CreateNewUserRequest.h
    DeleteUserRequest.h
    GetAccountNumberAdminRequest.h
    GetAccountNumberUserRequest.h
    LoginRequest.h
    MakeTransactionRequest.h
    RequestValidator.h
    ResponseHandler.h
    Signature.h
    TransferAmountRequest.h
    UpdateUserRequest.h
    ViewAccountDetailsRequest.h
    ViewBalanceRequest.h
    ViewBankDatabaseRequest.h
    ViewTransactionHistoryRequest.h
    Encryption.h
)


# Create a static library target named 'mylib' with the specified source files
add_library(mylib STATIC ${LIB_SOURCES})

# Link Qt libraries to 'mylib'
target_link_libraries(mylib
    PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Widgets
)

# Create an executable target named 'Client' with the specified source files
add_executable(Client ${SOURCES} ${HEADERS})

# Link the Qt libraries and the 'mylib' static library to the 'Client' executable
target_link_libraries(Client
    mylib
)

# Include installation directories for library and executable files
include(GNUInstallDirs)
install(TARGETS Client
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}  # Installation directory for executables
)
install(TARGETS mylib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}  # Installation directory for libraries
)