/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:29:33 by kmottus           #+#    #+#             */
/*   Updated: 2021/05/27 13:37:60 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "./libft/libft.h"		//Without it: implicit decl of ft_strlen in ft*/
# include <unistd.h>			//_ptrinf.c ?
# include <stdlib.h>
# include <stdarg.h>

size_t	ft_putstr_count(char *);
void	ft_printf_handle_modi(const char *s, size_t i);
int 	ft_printf_count_args(const char *s);
int		ft_printf_is_modifier(const char *s, size_t i);


#endif
