# C++ Repeat Assessment - Bug's Life II & Customer Management System

## Project Overview
This project implements two main components:
1. **Part A**: Customer Management System (40 marks)
2. **Part B**: A Bug's Life II Simulation (60 marks)

## Project Structure
```
├── src/
│   ├── customer/          # Part A - Customer Management System
│   │   ├── Customer.h
│   │   ├── Customer.cpp
│   │   └── main_customer.cpp
│   ├── bugs/              # Part B - Bug's Life II
│   │   ├── Bug.h
│   │   ├── Bug.cpp
│   │   ├── Crawler.h
│   │   ├── Crawler.cpp
│   │   ├── Hopper.h
│   │   ├── Hopper.cpp
│   │   ├── Board.h
│   │   ├── Board.cpp
│   │   └── main_bugs.cpp
│   └── common/            # Common utilities
│       ├── Position.h
│       └── Position.cpp
├── data/                  # Data files
│   ├── customers.txt
│   └── bugs.txt
├── build/                 # Build directory
├── CMakeLists.txt         # CMake configuration
└── Makefile              # Alternative build system
```

## Build Instructions
```bash
# Using CMake
mkdir build && cd build
cmake ..
make

# Using Makefile
make
```

## Running the Applications
```bash
# Customer Management System
./customer_system

# Bug's Life II Simulation
./bug_simulation
```

## Features Implemented
- Customer class with all required operators and methods
- Bug base class with derived Crawler and Hopper classes
- Board management system
- File I/O for data persistence
- Console-based user interface
- Basic SFML GUI implementation (for Part B)

## Git Commits
This project includes regular commits spaced out over the development period to demonstrate incremental development.
