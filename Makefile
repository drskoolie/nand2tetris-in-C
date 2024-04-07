# Define source directory
SRC_DIR := src

# Define object directory
OBJ_DIR := obj

# Define source files using wildcard function
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)

# Define object files using patsubst function
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -Iinclude

# Target executable
TARGET := my_program

# Default rule to build the executable
$(TARGET): $(OBJ_FILES)
	$(CC) $^ -o $@

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
