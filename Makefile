# Define directories
SRC_DIR := src
OBJ_DIR := obj
TEST_DIR := test

# Files and Objects
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
TEST_FILES := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.c,$(OBJ_DIR)/%.o,$(TEST_FILES))

# Compiler
CC := gcc

# Compiler flags
CFLAGS := 
CFLAGS += -Wall 
CFLAGS += -Wextra 
CFLAGS += -Iinclude
CFLAGS += -Iunity
CFLAGS += -g

# Target executable
TARGET := ./bin/nand
TEST_TARGET := ./bin/test_suite

# Default rule to build the executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build test executable
$(TEST_TARGET): $(TEST_OBJ_FILES) $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile test files into object files
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(TEST_CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET) $(TEST_TARGET)
