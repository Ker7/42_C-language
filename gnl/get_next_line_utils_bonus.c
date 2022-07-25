/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:50:00 by kmottus           #+#    #+#             */
/*   Updated: 2022/06/16 09:50:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*mem;
	unsigned char	*tmp;
	size_t			c;

	c = 0;
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	tmp = mem;
	while (c < (nmemb * size))
	{
		tmp[c] = 0;
		c++;
	}
	return (mem);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*copy;

	i = 0;
	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	copy = ft_calloc((len + 1), sizeof(char));
	if (copy == NULL || *s == '\0')
		return (NULL);
	while (i < len && s[start + i])
	{
		copy[i] = s[start + i];
		i++;
	}
	return (copy);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*copy;

	i = 0;
	copy = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*copy;

	i = 0;
	j = 0;
	copy = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
	{
		copy[i + j] = s2[j];
		j++;
	}
	return (copy);
}
