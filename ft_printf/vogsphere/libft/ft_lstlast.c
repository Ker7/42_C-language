/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:47:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/11/20 13:47:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		count;
	t_list	*cur;

	count = 1;
	if (!lst)
		return (0);
	cur = lst;
	while (cur->next != NULL)
	{
		cur = cur->next;
		count++;
	}
	return (cur);
}
