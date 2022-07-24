
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main() {
//	char	path[] = "41_with_nl";	// File location path
	char	path[] = "41pikk";	// File location path
	FILE	*file;
	int		fd;						// File descriptor
	char	*tmp;					// Buffer to hold read() filled characters
	int		r;						// return value of read()
	int 	c;

printf("\nHello, lets dig into: %s\n", path);

	c = 1;
	file = fopen(path, "r");
	tmp = malloc(1);
	tmp[0] = 0;
	if (!file)
	{
		perror(path);
		return (EXIT_FAILURE);
	}
	fd = fileno(file);
	r = 1;
//	while (r > 0)						//Start loop, while read() returned sth
	while (c < 47)
	{
		r = read(fd, tmp, 1);			// Read in one byte
/*		if (tmp[0] == '\n')				// IF	it is a newline character
			printf("\\n");				// THEN print out: '\n' 
		else if (tmp[0] == '\0')
			printf("\\0");
		else*/
//		if (r > 0)
		printf("\n%d: %c (%d), r:%d", c, (char)tmp[0], (int)tmp[0], r);	// print out the value
		c++;
	}

	free(tmp);
printf("\nEOF");

	return (0);
}
