/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:15:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/10/22 23:15:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && (s[i] != (c % 256)))
		i++;
	if (s[i] == (c % 256))
		return ((char *)s + i);
	return ((char *)0);
}
