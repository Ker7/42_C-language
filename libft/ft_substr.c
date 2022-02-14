/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:00:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/11/02 14:00:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*copy;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		copy = ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	else
		copy = ft_calloc(len + 1, sizeof(char));
	if (*s == '\0' || copy == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		copy[i] = s[start + i];
		i++;
	}
	return (copy);
}
