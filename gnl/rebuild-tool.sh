#!/bin/sh
make fclean &&
	make all &&
	gcc main.c get_next_line.a -I./ &&
	./a.out "text.txt"
