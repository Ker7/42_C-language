/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:50:00 by kmottus           #+#    #+#             */
/*   Updated: 2022/06/16 09:50:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "get_next_line.h"

static unsigned int static_line_marker = 0;

/*
 * ob	- output_buffer, old_name: string
 * s	- string in the workings
 * sret	- string to be returned
 */
char	*get_next_line(int fd)
{
	int		c;
	char	*s;
	void	*ob;
	ssize_t	rr;
//	char	*sret;
	char	cur;

printf("BUFFER_SIZE:\t%d\n", BUFFER_SIZE);
	c	= 0;
	ob	= ft_calloc(1, sizeof(char));
	s	= ft_calloc(BUFFER_SIZE, sizeof(char));
	rr	= read(fd, ob, 1);
//****** DEBUG ******//
printf("rr:%ld", rr);
	while (c < BUFFER_SIZE && rr == 1)
	{

//****** DEBUG ******//
//printf("%s", (char *)ob);	//OK!
//*******************//
		cur = *((char *) ob);

//printf(" - p.%p. s.%s. \n", &string, (char *)string); //OK!
//printf(" - p.%p. s.%s. p.%p. c.%c.\n", &ob, (char *)ob, (char *)ob, cur);
//printf("slm:%d.", static_line_marker);

		s[c] = cur;
		if (cur == '\n')//if'\n' return add char, line number, and return
		{
//printf("%ld-%ld-", ft_strlen(ob), ft_strlen(s));
			static_line_marker++;
//printf(":;%d;:", static_line_marker);			
			free(ob);
			return (s);
		}
		// Print to variable :: max_line_length
		//printf("%c", cur);
		ft_bzero(ob, 1);
		rr = (read(fd, ob, sizeof(char)));
		c++;
	}

	free(ob);
	free(s);
	return (NULL);
}
