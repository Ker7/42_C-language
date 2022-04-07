/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prf_conv_cspdi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:42:00 by kmottus           #+#    #+#             */
/*   Updated: 2022/03/08 14:42:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/* @returns the number on characters outputted */
size_t	conv_c(char ivar)
{
	return (write(1, &ivar, 1));
}

/* @returns the number on characters outputted */
size_t	conv_s(char *ivar)
{
	return (ft_putstr_count(ivar));
}

size_t	conv_p(void *ivar)
{
	size_t	ret;

	ret = 0;
printf("%p", ivar);
	return (ret);
}

size_t	conv_di(int ivar)
{
	size_t	ret;

	ret = 0;
printf("%d", ivar);
	return (ret);
}
