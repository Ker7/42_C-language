/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:27:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/11/10 16:27:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (*(s + i))
	{
		if (*(s + (i + 1)) != c && (s + (i + 1)))
			count++;
		if (*(s + i) == c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		start;
	int		end;
	char	**string;

	if (!str)
		return (NULL);
	i = 0;
	start = 0;
	string = ft_calloc(ft_count((char *)str, c) + 1, sizeof(char *));
	if (!string)
		return (NULL);
	while (*(str + start))
	{
		while (*(str + start) == c && *(str + start))
			start++;
		end = start;
		while (*(str + end) != c && *(str + end))
			end++;
		if (*(str + start))
			string[i] = ft_substr(str, start, end - start);
		i++;
		start = end;
	}
	return (string);
}
