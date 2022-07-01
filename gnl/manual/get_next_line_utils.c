/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:50:00 by kmottus           #+#    #+#             */
/*   Updated: 2022/06/16 09:50:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	c;
	char	*p;

	c = 0;
	p = (char *)s;
	while (c < n)
	{
		p[c] = 0;
		c++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb);
	return (p);
}

size_t	ft_strlen(char *s)
{
	size_t	c;

	c = 0;
	while(s[c])
		c++;
	return (c);
}
