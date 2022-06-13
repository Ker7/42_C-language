/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:54:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/11/20 09:54:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*cpy;
	size_t			len;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	cpy = ft_calloc(len + 1, sizeof(char));
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, s, len);
	while (i < len)
	{
		cpy[i] = f(i, s[i]);
		i++;
	}
	return (cpy);
}
