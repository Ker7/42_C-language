/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:06:00 by kmottus           #+#    #+#             */
/*   Updated: 2022/06/09 07:06:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_strrev(char *str)
{
	int		c;
	int		len;
	char	*s;
	char	*e;
	char	tmp;

	len = ft_strlen(str);
	c = 0;
	s = str;
	e = str;
	while (c < len - 1)
	{
		e++;
		c++;
	}
	c = 0;
	while (c < len / 2)
	{
		tmp = *e;
		*e = *s;
		*s = tmp;
		s++;
		e--;
		c++;
	}
}
