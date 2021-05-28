/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:08:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/05/27 22:08:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	counter;
	unsigned char	*mem;

	counter = 0;
	mem = s;
	while (counter < n)
	{
		mem[counter] = '\0';
		counter++;
	}
}
