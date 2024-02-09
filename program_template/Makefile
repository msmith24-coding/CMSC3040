# Program Information.
PROGRAM_NAME = program_template
TARGET_NAME = program_template

# Compiler Inforamtion.
CC = g++

# CXX Flags are defined here.
DEBUG_FLAGS = -g
OPTIMIZATION_FLAGS = -O3
STANDARD_FLAGS = --std=c++20
WARNING_FLAGS = -Wpedantic -Wall -Wextra -Wmisleading-indentation -Wunused -Wuninitialized -Wshadow -Wconversion -Wfloat-equal -Wparentheses -Wunreachable-code
CXXFLAGS = $(DEBUG_FLAGS) $(OPTIMIZATION_FLAGS) $(STANDARD_FLAGS) $(WARNING_FLAGS)

# Directories are defined here.
INCLUDE_DIR = include/  

# Source files that should be compiled are defined here.
SOURCES = src/main.cpp
#SOURCES += src/other.cpp

# Converts *.cpp source files into compiled *.o files and stores them into the ./obj directory.
OBJS = $(SOURCES:src/%.cpp=obj/%.o)

ifeq ($(OS),Windows_NT)
    RM_CMD = del /Q /F 
    OUT = $(TARGET_NAME).exe
    TAR_CMD = echo "[ERR] tar is not supported on windows."
    ZIP_CMD = echo "[ERR] zip is currently not implemented." 
else
    RM_CMD = rm -rf
    OUT = $(TARGET_NAME) 
    TAR_CMD = tar -czvf ../archives/$(PROGRAM_NAME).tar.gz ../$(PROGRAM_NAME)
    ZIP_CMD = zip -r ../archives/$(PROGRAM_NAME).zip ../$(PROGRAM_NAME) 
endif

# Actions are defined here.
.PHONY: all clean tar zip obj

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $@

# Output build commands are defined here.
obj/%.o: src/%.cpp | obj
	$(CC) -c $(CXXFLAGS) $< -o $@ -I$(INCLUDE_DIR)

# Create the ./obj directory.
obj:
	@mkdir -p obj

# Utility Actions
clean:
	$(RM_CMD) obj $(OUT)

tar:
	$(RM_CMD) obj $(OUT)
	$(TAR_CMD)

zip:
	$(RM_CMD) obj $(OUT)
	$(ZIP_CMD)

