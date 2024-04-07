compile: 
	#!/usr/bin/env bash
	for file in src/*.c;
	do
		gcc -c -Iinclude $file -o obj/$(basename $file .c).o
	done
