/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:51:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/05/27 21:51:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Making an input character to be of type unsigned
 * From UNIT test I learned the values for negative
 * range, especially the '- one' values.
 * +256 is added because else it did not mod the -*
 */

int	ft_tolower(int c)
{
	if (c < -1 && c > -129)
		c = (c + 256) % 256;
	if (c <= 90 && c >= 65)
		c += 32;
	return (c);
}
