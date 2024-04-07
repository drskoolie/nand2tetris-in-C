CC=gcc
CFLAGS=-Iinclude -g -std=c17

# List all header files in the include directory
DEPS := $(wildcard include/*.h)

# Define the source files
SRC := $(wildcard src/*.c)
TEST_SRC := $(wildcard tests/*.c)

# Generate corresponding object file names
OBJ := $(patsubst src/%.c, obj/%.o, $(SRC))
TEST_OBJ := $(patsubst tests/%.c, obj/%.o, $(TEST_SRC))

# Rule to generate object files
obj/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Rule to build the final executable
tetris: $(OBJ)
	$(CC) -o bin/$@ $^ $(CFLAGS)

tests: $(TEST_OBJ) $(OBJ)
	$(CC) -o bin/tests $^ $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	./bin/tests

.PHONY: clean
clean:
	rm -f obj/*.o bin/tetris bin/tests
