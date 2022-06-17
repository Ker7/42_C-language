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

//static unsigned int line_mrkr = 0;

char	*get_next_line(int fd)
{
	unsigned int	c;
	unsigned int	buffer;
	char 			*s;
	void 			*string;
	int				ret;
	char			cur;

	c = 0;//line_mrkr;
	buffer = 128;
	string = malloc(sizeof(char));
	s = malloc(128 * sizeof(char));
	ret = read(fd, string, sizeof(char));	
	while (c < buffer && ret == 1)
	{
		cur = *((char *) string);
//printf(" - p.%p. s.%s. \n", &string, (char *)string); //OK!
//printf(" - p.%p. s.%s. p.%p. c.%c.\n", &string, (char *)string, (char *)string, cur);	//PL!
//		printf("%s", (char *)string);	//OK!
		s[c] = cur;
		if (cur == '\n')	//if '\n' then return add char, line number, and return
		{
			free(string);
			return (s);
		}
		// Print to variable :: max_line_length
		//printf("%c", cur);
		ret = (read(fd, string, sizeof(char)));
		c++;
	}

	free(string);
	free(s);
	return (NULL);
}
