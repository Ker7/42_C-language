#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

char	*get_next_line(int fd);

/* ***************************************************************************/

static unsigned int line_mrkr = 0;

int main(int argc, char **argv)
{
	char	*path;
	FILE	*file;
	char	*curline;

	if  (argc < 1)
		return (EXIT_FAILURE);
	path = argv[1];
	file = fopen(path, "r");
	if (!file)
	{
		perror(path);
		return (EXIT_FAILURE);		
	}

	printf("\nBUFFER_SIZE=%d", BUFFER_SIZE);
	printf("\nThe file descriptor of %s is: %d.\n", path, fileno(file));
//	printf("\nget_next_line returns:\nL1: <%s>L2: <%s>\n", line1, line2);
	
	curline = get_next_line(fileno(file));
//	printf("%s", curline);

	while (curline != NULL)
	{
		printf("%s", curline);
		curline = get_next_line(fileno(file));
	}

	if (fclose(file))
	{
		return (EXIT_FAILURE);
		perror(path);
	}

}
