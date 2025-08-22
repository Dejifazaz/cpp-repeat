# Makefile for C++ Repeat Assessment
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Directories
SRCDIR = src
BUILDDIR = build
BINDIR = $(BUILDDIR)/bin
DATADIR = data

# Source files
CUSTOMER_SOURCES = $(SRCDIR)/customer/Customer.cpp $(SRCDIR)/customer/main_customer.cpp
BUG_SOURCES = $(SRCDIR)/bugs/Bug.cpp $(SRCDIR)/bugs/Crawler.cpp $(SRCDIR)/bugs/Hopper.cpp $(SRCDIR)/bugs/Board.cpp $(SRCDIR)/bugs/main_bugs.cpp

# Object files
CUSTOMER_OBJECTS = $(CUSTOMER_SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)
BUG_OBJECTS = $(BUG_SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# Executables
CUSTOMER_EXEC = $(BINDIR)/customer_system
BUG_EXEC = $(BINDIR)/bug_simulation

# Default target
all: $(CUSTOMER_EXEC) $(BUG_EXEC)

# Create directories
$(BUILDDIR):
	mkdir -p $(BUILDDIR)
	mkdir -p $(BINDIR)
	mkdir -p $(BUILDDIR)/customer
	mkdir -p $(BUILDDIR)/bugs

# Customer Management System
$(CUSTOMER_EXEC): $(CUSTOMER_OBJECTS) | $(BUILDDIR)
	$(CXX) $(CUSTOMER_OBJECTS) -o $@

# Bug Simulation System
$(BUG_EXEC): $(BUG_OBJECTS) | $(BUILDDIR)
	$(CXX) $(BUG_OBJECTS) -o $@

# Compile customer objects
$(BUILDDIR)/customer/%.o: $(SRCDIR)/customer/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile bug objects
$(BUILDDIR)/bugs/%.o: $(SRCDIR)/bugs/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILDDIR)

# Run customer system
run-customer: $(CUSTOMER_EXEC)
	cd $(BINDIR) && ./customer_system

# Run bug simulation
run-bugs: $(BUG_EXEC)
	cd $(BINDIR) && ./bug_simulation

# Copy data files
data: | $(BUILDDIR)
	cp -r $(DATADIR) $(BINDIR)/

# Install dependencies (for macOS)
install-deps:
	brew install cmake

# Help
help:
	@echo "Available targets:"
	@echo "  all              - Build both executables"
	@echo "  customer_system  - Build customer management system"
	@echo "  bug_simulation   - Build bug simulation system"
	@echo "  clean            - Remove build files"
	@echo "  run-customer     - Run customer system"
	@echo "  run-bugs         - Run bug simulation"
	@echo "  data             - Copy data files to build directory"
	@echo "  install-deps     - Install dependencies (macOS)"

.PHONY: all clean run-customer run-bugs data install-deps help
