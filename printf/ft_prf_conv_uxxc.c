/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prf_conv_uxxc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:42:00 by kmottus           #+#    #+#             */
/*   Updated: 2022/03/08 14:42:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


size_t	conv_u(unsigned int ivar)
{
	size_t	ret;

	ret = 0;
printf("%u", ivar);
	return (ret);
}

size_t	conv_x(int ivar)
{
	size_t	ret;

	ret = 0;
printf("%x", ivar);
	return (ret);
}

size_t	conv_xc(int ivar)
{
	size_t	ret;

	ret = 0;
printf("%X", ivar);
	return (ret);
}

size_t	conv_pp()
{
	char	p;

	p = '%';
	return (write(1, &p, 1));
}
