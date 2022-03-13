/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:16:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/09/28 21:16:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	l;
	size_t	n_len;

	i = 0;
	l = 0;
	n_len = ft_strlen(needle);
	if (n_len == 0 || haystack == needle)
		return ((char *)haystack);
	while (haystack[i])
	{
		l = 0;
		while (haystack[i + l] != '\0' && needle[l] != '\0'
			&& haystack[i + l] == needle[l] && i + l < n)
		{
			if (needle[l + 1] == '\0')
				return ((char *)haystack + i);
			l++;
		}
		i++;
	}
	return (0);
}
