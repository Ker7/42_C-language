/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:32:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/05/27 22:32:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Test comment
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*mem;
	unsigned char	*tmp;
	size_t			counter;

	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	tmp = mem;
	counter = 0;
	while (counter < (nmemb * size))
	{
		tmp[counter] = 0;
		counter++;
	}
	return (mem);
}
