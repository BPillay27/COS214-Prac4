# Compiler & flags
CXX       := g++
CXXFLAGS  := -std=c++11 -g -Wall -Wextra -Wpedantic -MMD -MP

# Executable name
TESTING   := main

# Sources/objects
COMMON_SRCS := $(filter-out %Main.cpp, $(wildcard *.cpp))
COMMON_OBJS := $(COMMON_SRCS:.cpp=.o)
COMMON_DEPS := $(COMMON_OBJS:.o=.d)

# Valgrind
VAL     := valgrind
VGFLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes \
           --errors-for-leak-kinds=all --error-exitcode=1 -s

# Default target
.PHONY: all
all: $(TESTING)

# Compile .cpp -> .o (+ .d via -MMD)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link (ensure TestingMain.cpp exists -> TestingMain.o)
$(TESTING): TestingMain.o $(COMMON_OBJS)
	$(CXX) -o $@ $^

# Run
.PHONY: test
test: $(TESTING)
	./$(TESTING) $(ARGS)

# Valgrind test
.PHONY: vt
vt: $(TESTING)
	$(VAL) $(VGFLAGS) ./$(TESTING) $(ARGS)

# GDB
.PHONY: gdb
gdb: $(TESTING)
	gdb --args ./$(TESTING) $(ARGS)

# Cleaning
.PHONY: clean
clean:
	rm -f *.o *.d $(TESTING) core* vgcore*

# Zip current folder (recursive) after a clean build
.PHONY: zip
zip: clean
	zip -r u21516261.zip .

# Rebuild the zip from scratch
.PHONY: rezip
rezip:
	rm -f u21516261.zip
	$(MAKE) zip

# Include auto-generated header deps
-include $(COMMON_DEPS)
