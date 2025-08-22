cmake_minimum_required(VERSION 3.10)
project(CppRepeatAssessment)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Common source files
set(COMMON_SOURCES
    src/common/Position.h
)

# Customer Management System (Part A)
set(CUSTOMER_SOURCES
    src/customer/Customer.h
    src/customer/Customer.cpp
    src/customer/main_customer.cpp
)

# Bug Simulation System (Part B)
set(BUG_SOURCES
    src/bugs/Bug.h
    src/bugs/Bug.cpp
    src/bugs/Crawler.h
    src/bugs/Crawler.cpp
    src/bugs/Hopper.h
    src/bugs/Hopper.cpp
    src/bugs/Board.h
    src/bugs/Board.cpp
    src/bugs/main_bugs.cpp
)

# Create executables
add_executable(customer_system ${CUSTOMER_SOURCES})
add_executable(bug_simulation ${BUG_SOURCES})

# Set output directories
set_target_properties(customer_system PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

set_target_properties(bug_simulation PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Copy data files to build directory
file(COPY data DESTINATION ${CMAKE_BINARY_DIR}/bin)
