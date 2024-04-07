compile: 
	#!/usr/bin/env bash
	for file in src/*.c;
	do
		gcc -c -Iinclude $file -o obj/$(basename $file .c).o
	done

link: compile
	#!/usr/bin/env bash
	gcc obj/*.o -o ./bin/nand

clean:
	@rm -rf obj/*
	@rm -rf bin/*
	@echo "Cleanup completed"
