/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:00:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/10/18 14:00:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_check_edgecases(int i, unsigned long res, int sign)
{
	if (i > 24)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (sign * res);
}

int	ft_atoi(const char *nptr)
{
	int				i;
	unsigned long	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)) && nptr[i])
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && nptr[i])
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (ft_atoi_check_edgecases(i, res, sign));
}
