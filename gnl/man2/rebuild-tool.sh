#!/bin/sh
gcc -c get_next_line.c get_next_line_utils.c -DBUFFER_SIZE=42
ar rc get_next_line.a get_next_line.o get_next_line_utils.o
gcc main.c get_next_line.a
./a.out "41_with_nl"
#./a.out "41-srt"
#./a.out "smpl_less-than-buffer.txt"
#&&./a.out "smpl_more-than-buffer.txt"

#make fclean
