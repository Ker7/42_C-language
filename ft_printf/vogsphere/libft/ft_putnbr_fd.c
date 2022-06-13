/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:32:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/09/28 20:32:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10 + '0'), fd);
	}
	else
	{
		ft_putchar_fd((n + '0'), fd);
	}
}

/* put out an unsinged integer
 */
int	ft_putnbr_fd_cnt(unsigned long long n, int fd)
{
	int	cnt;

	cnt = 0;
	if (n > 9)
	{
		cnt = ft_putnbr_fd_cnt(n / 10, fd);
		ft_putchar_fd((n % 10 + '0'), fd);
		cnt++;
	}
	else
	{
		ft_putchar_fd((n + '0'), fd);
		cnt++;
	}
	return (cnt);
}
