# Define directories
SRC_DIR := src
OBJ_DIR := obj
TEST_DIR := test
BIN_TEST_DIR := ./bin/test

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

TEST_CFLAGS := $(CFLAGS)

# Target executable
TARGET := ./bin/nand
TEST_TARGET := ./bin/test_suite

# Default rule to build the executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Excluding main.o for the test suite linkage
OBJ_FILES_WITHOUT_MAIN := $(filter-out $(OBJ_DIR)/main.o,$(OBJ_FILES))

# Rule to make the test directory
$(BIN_TEST_DIR):
	@echo "Creating directory $(BIN_TEST_DIR)"
	mkdir -p $@

# Rule to compile each test into its own program
$(BIN_TEST_DIR)/%: $(TEST_DIR)/%.c $(OBJ_FILES_WITHOUT_MAIN) | $(BIN_TEST_DIR)
	$(CC) $(CFLAGS) $< $(OBJ_FILES_WITHOUT_MAIN) -o $@ -lm

# Phony targets for standard make commands
.PHONY: all clean test

all: $(TEST_TARGETS)

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_TEST_DIR)/*

# Test rule to run all tests
test: $(TEST_TARGETS)
	@bash -c 'for test in $^ ; do \
		echo "Running $$test..." ; \
		./$$test ; \
		done'
