/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:47:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/10/09 17:47:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	sum;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	sum = dlen + slen;
	if (dlen > n || n == 0)
		return (slen + n);
	slen = 0;
	while (src[slen] && dlen + 1 < n)
	{
		dst[dlen++] = src[slen++];
	}
	dst[dlen] = '\0';
	return (sum);
}
