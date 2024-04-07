CC=gcc
CFLAGS=-Iinclude -g -std=c17

# List all header files in the include directory
DEPS := $(wildcard include/*.h)

# Define the source files
SRC := $(wildcard src/*.c)

# Generate corresponding object file names
OBJ := $(patsubst src/%.c, obj/%.o, $(SRC))

# Rule to generate object files
obj/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Rule to build the final executable
NAND2Tetris: $(OBJ)
	$(CC) -o bin/$@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f obj/*.o bin/NAND2Tetris
