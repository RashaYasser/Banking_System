cmake_minimum_required(VERSION 3.10)

project(BankingSystem VERSION 1.0 LANGUAGES CXX)

# Find Qt6 package
find_package(Qt6 REQUIRED COMPONENTS Core Network)

# Include directories
include_directories(${Qt6Core_INCLUDE_DIRS} ${Qt6Network_INCLUDE_DIRS})

# Define sources and headers
set(SOURCES
    main.cpp
    DataBaseManager.cpp
    MyServer.cpp
    MyServerHandler.cpp
    RequestHandler.cpp
)

set(HEADERS
    DataBaseManager.h
    Memento.h
    MyServer.h
    MyServerHandler.h
    RequestHandler.h
)

# Add executable
add_executable(BankingSystem ${SOURCES} ${HEADERS})

# Link Qt6 libraries
target_link_libraries(BankingSystem PRIVATE Qt6::Core Qt6::Network)

# Specify C++ standard
set_target_properties(BankingSystem PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

# Set the working directory for the executable
set_target_properties(BankingSystem PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
