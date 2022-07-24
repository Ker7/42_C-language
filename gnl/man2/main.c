#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

char	*get_next_line(int fd);

int main(int argc, char **argv)
{
	int		i;
	char	*path;
	FILE	*file;
	char	*curline;
	int		_last_line_flag;

	_last_line_flag = 2;
	i = 0;
	if  (argc < 1)
		return (EXIT_FAILURE);
	path = argv[1];
	file = fopen(path, "r");
	if (!file)
	{
		perror(path);
		return (EXIT_FAILURE);		
	}

//	printf("\nBUFFER_SIZE=%d\n", BUFFER_SIZE);
	printf("\nThe file descriptor of %s is: %d.\n", path, fileno(file));
//	printf("\nget_next_line returns:\nL1: <%s>L2: <%s>\n", line1, line2);
	
	curline = get_next_line(fileno(file));
//	printf("c>%s", curline);

	while (_last_line_flag > 0)
	{
		printf("%d'th run: \"%s\"", i, curline);
		curline = get_next_line(fileno(file));
		i++;
		if (curline == NULL)
			_last_line_flag--;
	}	

/*
	printf("\n1st run: %s", curline);
	curline = get_next_line(fileno(file));
	printf("\n2nd run: %s", curline);
*/

	if (fclose(file))
	{
		return (EXIT_FAILURE);
		perror(path);
	}

}
