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
	char	*line1;
	char	*line2;

	if  (argc < 1)
		return (EXIT_FAILURE);
	path = argv[1];
	file = fopen(path, "r");
	if (!file)
	{
		perror(path);
		return (EXIT_FAILURE);		
	}

	line1 = get_next_line(fileno(file));
	line2 = get_next_line(fileno(file));

	printf("\n");
	printf("\nThe file descriptor of %s is: %d.\n", path, fileno(file));
	printf("\nget_next_line returns:\nL1: <%s>L2: <%s>\n", line1, line2);



	if (fclose(file))
	{
		return (EXIT_FAILURE);
		perror(path);
	}

}
