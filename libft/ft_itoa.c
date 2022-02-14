/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:37:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/11/16 17:37:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(long n)
{
	int	len;

	len = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		len++;
	}
	if (len > 10)
		len = 10;
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*res;
	int		is_negative;
	long	nn;

	nn = n;
	is_negative = 0;
	if (nn < 0)
		is_negative = 1;
	if (is_negative)
		nn *= -1;
	i = 0;
	res = ft_calloc(ft_itoa_len(n) + is_negative + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	while (nn > 9)
	{
		res[ft_itoa_len(n) - 1 - i + is_negative] = nn % 10 + '0';
		nn /= 10;
		i++;
	}
	res[ft_itoa_len(n) - 1 - i + is_negative] = nn + '0';
	if (is_negative)
		res[0] = '-';
	return (res);
}
