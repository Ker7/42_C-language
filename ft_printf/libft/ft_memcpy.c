/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:15:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/09/30 21:15:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*ptr;
	const char	*s;

	if (len == 0 || dest == src)
		return (dest);
	ptr = dest;
	s = src;
	while (len--)
		*ptr++ = *s++;
	return (dest);
}
