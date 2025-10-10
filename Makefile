# Compiler & flags
CXX       := g++
CXXFLAGS  := -std=c++11 -g -Wall -Wextra -Wpedantic -MMD -MP

# Executable name
TARGET    := main

# Sources/objects
# Build all .cpp files EXCEPT main.cpp as common objects
COMMON_SRCS := $(filter-out main.cpp, $(wildcard *.cpp))
COMMON_OBJS := $(COMMON_SRCS:.cpp=.o)
COMMON_DEPS := $(COMMON_OBJS:.o=.d) main.d

# Valgrind
VAL     := valgrind
VGFLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes \
           --errors-for-leak-kinds=all --error-exitcode=1 -s

# Default target
.PHONY: all
all: $(TARGET)

# Compile .cpp -> .o (+ .d via -MMD)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile main.cpp separately (also emits main.d)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link main.o + common objects
$(TARGET): main.o $(COMMON_OBJS)
	$(CXX) -o $@ $^

# Run
.PHONY: test
test: $(TARGET)
	./$(TARGET) $(ARGS)

# Valgrind test
.PHONY: vt
vt: $(TARGET)
	$(VAL) $(VGFLAGS) ./$(TARGET) $(ARGS)

# GDB
.PHONY: gdb
gdb: $(TARGET)
	gdb --args ./$(TARGET) $(ARGS)

# Cleaning
.PHONY: clean
clean:
	rm -f *.o *.d $(TARGET) core* vgcore*

# Zip current folder (recursive) after a clean build
.PHONY: zip
zip: clean
	zip -r u21516261.zip .

# Rebuild the zip from scratch
.PHONY: rezip
rezip:
	rm -f u21516261.zip
	$(MAKE) zip

# Include auto-generated header deps (safe if files don't exist)
-include $(COMMON_DEPS)
