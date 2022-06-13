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

#include "../inc/ft_printf.h"
//#include "../inc/libft.h"

#include <stdio.h>

/* @returns the number on characters outputted */
size_t	conv_c(char ivar)
{
	return (write(1, &ivar, 1));
}

/* @returns the number on characters outputted or (null) */
size_t	conv_s(char *ivar)
{
	if (ivar != NULL)
		return (ft_putstr_count(ivar));
	else
		return (write(1, "(null)", 6));
}

/* Deal with %p modifier, add 0x in front and write out mem loc in hex
 * Devlog:
 * Pointless allocation, just making friends with malloc/free
 * - or is it? I still have to turn it around, this is still best option
 *
 */
size_t	conv_p(void *ivar)
{
	unsigned long long int	dec;
	int						cnt;
	char					*wbin;

	if (ivar == NULL || !ivar || ivar == 0)
		return (write(1, "(nil)", 5));
	dec = (unsigned long long int)ivar;
	cnt = 0;
	wbin = ft_calloc(sizeof(char), 33);
	write(1, &"0x", 2);
	while (dec > 0)
	{
		if ((dec % 16) < 10)
			wbin[cnt] = ((dec % 16) + 48);
		else
			wbin[cnt] = (dec % 16) + 87;
		dec /= 16;
		cnt += 1;
	}
	ft_strrev(wbin);
	cnt = ft_putstr_count(wbin);
	cnt += 2;
	free(wbin);
	return (cnt);
}

size_t	conv_di(int ivar)
{
	if (!ivar || ivar == 0)
		return (write(1, "0", 1));
	if (ivar == -2147483648)
		return (write(1, "-2147483648", 11));
	if (ivar < 0)
	{
		write(1, &"-", 1);
		ivar = -1 * ivar;
		return (ft_putnbr_fd_cnt((unsigned long)ivar, 1) + 1);
	}
	return (ft_putnbr_fd_cnt((unsigned long)ivar, 1));
}
