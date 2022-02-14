/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:00:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/05/27 17:00:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		k;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, (int)s1[i]) != NULL)
		i++;
	k = ft_strlen(s1) - 1;
	while (k > i && ft_strchr(set, (int)s1[k]) != NULL)
		k--;
	trim = (char *)malloc(sizeof(char) * ((k - i) + 2));
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, (s1 + i), ((k - i) + 2));
	return (trim);
}
