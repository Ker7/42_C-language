/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:29:33 by kmottus           #+#    #+#             */
/*   Updated: 2022/04/08 13:37:60 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

size_t	conv_c(char ivar);
size_t	conv_s(char *ivar);
size_t	conv_p(void *ivar);
size_t	conv_di(int ivar);
size_t	conv_u(unsigned int ivar);
size_t	conv_x(int ivar);
size_t	conv_xc(int ivar);

void	ft_strrev(char *str);
size_t	ft_printf_handle_argument(char str, va_list list_a);
size_t	ft_putstr_count(char *s);
void	ft_printf_handle_modi(const char *s, size_t i);
int		ft_printf_count_args(const char *s);
int		ft_printf_is_modifier(const char *s, size_t i);

int		ft_printf(const char *s, ...);

#endif
