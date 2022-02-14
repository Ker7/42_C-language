/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:24:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/10/23 23:24:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	size_t	size;
	char	*copy;

	i = 0;
	size = ft_strlen(s) + 1;
	copy = ft_calloc(size, sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (i < (int)size - 1)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
