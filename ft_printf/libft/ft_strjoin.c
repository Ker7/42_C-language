/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:00:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/10/28 13:00:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*copy;

	s1_len = ft_strlen(s1) + 1;
	s2_len = ft_strlen(s2) + 1;
	copy = ft_calloc(s1_len + s2_len - 1, sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s1, s1_len);
	ft_strlcat(copy, (char *)s2, s1_len + s2_len - 1);
	return (copy);
}
