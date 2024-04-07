CC=gcc
CFLAGS=-Iinclude -g
DEPS = $(wildcard include/*.h)
OBJ = $(patsubst src/%.c, obj/%.o, $(wildcard src/*.c))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

NAND2Tetris: $(OBJ)
	$(CC) -o bin/$@ $^ $(CFLAGS)

clean:
	rm -f obj/*.o bin/NAND2Tetris
