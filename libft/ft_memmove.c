/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:58:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/12/08 14:47:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* memcpy is called only after the test for memory overlapping
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if ((unsigned long)(dest - src) >= (unsigned long) n)
		return (ft_memcpy(dest, src, n));
	while (n-- > 0)
		*((char *) dest + n) = *((char *) src + n);
	return (dest);
}
