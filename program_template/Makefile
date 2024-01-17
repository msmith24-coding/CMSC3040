# Program Information.
PROGRAM_NAME = program_template
TARGET_NAME = program_template 

# Compiler Inforamtion.
CC = g++

# CXX Flags are defined here.
DEBUG_FLAGS = -g
OPTIMIZATION_FLAGS = -O2
STANDARD_FLAGS = --std=c++20
WARNING_FLAGS = -Wall -Wextra -Wpedantic -Wnon-virtual-dtor -Wold-style-cast -Wuninitialized -Winit-self -Wparentheses -Wdangling-else
CXXFLAGS = $(DEBUG_FLAGS) $(OPTIMIZATION_FLAGS) $(STANDARD_FLAGS) $(WARNING_FLAGS)

# Directories are defined here.
INCLUDE_DIR = ./include 
SOURCE_DIR = ./src 
OBJ_DIR = ./obj

# Source files that should be compiled are defined here.
SOURCES = $(SOURCE_DIR)/main.cpp
#SOURCE_DIR += $(SOURCE_DIR)/other.cpp

# Converts *.cpp source files into compiled *.o files and stores them into the ./obj directory.
OBJS = $(SOURCES:$(SOURCE_DIR)/%.cpp=$(OBJ_DIR)/%.o)

ifeq ($(OS), Windows_NT)
    RM_CMD = del /Q /F 
    OUT = $(TARGET_NAME).exe
    TAR_CMD = echo "[ERR] tar is not supported on windows."
    ZIP_CMD = echo "[ERR] zip is currently not implemented." 
else
    RM_CMD = rm -rf
    OUT = $(TARGET_NAME).out 
    TAR_CMD = tar -czvf ../archives/$(PROGRAM_NAME).tar.gz ../$(PROGRAM_NAME)
    ZIP_CMD = zip -r ../archives/$(PROGRAM_NAME).zip ../$(PROGRAM_NAME) 
endif

# Actions are defined here.
.PHONY: all clean tar zip $(OBJ_DIR)

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $@

# Output build commands are defined here.
$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -c $(CXXFLAGS) $< -o $@ -I$(INCLUDE_DIR)

# Create the ./obj directory.
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Utility Actions
clean:
	$(RM_CMD) $(OBJ_DIR) $(OUT)

tar:
	$(RM_CMD) $(OBJ_DIR) $(OUT)
	$(TAR_CMD)

zip:
	$(RM_CMD) $(OBJ_DIR) $(OUT)
	$(ZIP_CMD)

