/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:49:00 by kmottus           #+#    #+#             */
/*   Updated: 2021/12/02 10:59:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || *lst == NULL)
		return ;
	while (*lst)
	{
		tmp = *lst;
		del(tmp->content);
		*lst = tmp->next;
		free(tmp);
	}
}
