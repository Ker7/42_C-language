#!/bin/sh
gcc -c get_next_line.c get_next_line_utils.c -DBUFFER_SIZE=421
ar rc get_next_line.a get_next_line.o get_next_line_utils.o
gcc main.c get_next_line.a -DBUFFER_SIZE=420
./a.out "smpl_less-than-buffer.txt"
#&&./a.out "smpl_more-than-buffer.txt"
