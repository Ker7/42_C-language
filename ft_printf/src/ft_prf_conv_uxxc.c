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

#include "../inc/ft_printf.h"

size_t	conv_u(unsigned int ivar)
{
	if (!ivar || ivar == 0)
		return (write(1, "0", 1));
	return (ft_putnbr_fd_cnt((unsigned int)ivar, 1));
}

size_t	conv_x(int ivar)
{
	unsigned int	dec;
	int				cnt;
	char			*wbin;

	if (!ivar || ivar == 0)
		return (write(1, "0", 1));
	dec = (unsigned int)ivar;
	cnt = 0;
	wbin = ft_calloc(sizeof(char), 33);
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
	free(wbin);
	return (cnt);
}

size_t	conv_xc(int ivar)
{
	unsigned int	dec;
	int				cnt;
	char			*wbin;

	if (!ivar || ivar == 0)
		return (write(1, "0", 1));
	dec = (unsigned int)ivar;
	cnt = 0;
	wbin = ft_calloc(sizeof(char), 33);
	while (dec > 0)
	{
		if ((dec % 16) < 10)
			wbin[cnt] = ((dec % 16) + 48);
		else
			wbin[cnt] = (dec % 16) + 87;
		if (ft_isalpha(wbin[cnt]))
			wbin[cnt] = ft_toupper(wbin[cnt]);
		dec /= 16;
		cnt += 1;
	}
	ft_strrev(wbin);
	cnt = ft_putstr_count(wbin);
	free(wbin);
	return (cnt);
}
