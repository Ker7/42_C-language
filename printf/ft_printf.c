/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:42:00 by kmottus           #+#    #+#             */
/*   Updated: 2022/03/08 14:42:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_prf_conv_cspdi.c"
#include "ft_prf_conv_uxxc.c"

#include <stdio.h>


/* arg0 string gets written out
 * @return the lenght outputted */
size_t	ft_putstr_count(char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		write(1, s, 1);
		s++;
		i++;
	}
	return (i);
}

/* wip func to deal with modifiers @todo abandon this func */
void ft_printf_handle_modi(const char *s, size_t i)
{
	char	*mlist;

	mlist = "cspdiuxX%";//@ POOLELII!.w
	printf("\n\n@TodoStr: %s.c: %c.Modifiers: %s", s, s[i], mlist);

}

int	ft_printf_count_args(const char *s)
{
	size_t	i;		// string iterator
	size_t	arg_c;	// Argument count to be returned...

	i = 0;
	arg_c = 0;		// If we find % and the next&prev is not %, arg_c +one...
	while(s[i] != '\0')
	{
		if (ft_printf_is_modifier(s, i) != 0)
		{
			arg_c++;
			i++;
		}
		i++;
	}
	return (arg_c);
}

/* Return 1 if currently dealing with modifier */
int	ft_printf_is_modifier(const char *s, size_t i)
{
	if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]) != NULL)
	{
		return (1);
	}
	return (0);
}

/* Give the modifier char, list of arguments and route to correct disp fn     */
/* @return value is the lenght of argument that was being printed			  */
size_t	ft_printf_handle_argument(char str, va_list list_a)
{
	if ('c' == str)
		return (conv_c(va_arg(list_a, int)));
	if ('s' == str)
		return (conv_s(va_arg(list_a, char*)));
	if ('p' == str)
		return (conv_p(va_arg(list_a, void*)));
	if ('d' == str || 'i' == str)
		return (conv_di(va_arg(list_a, int)));
	if ('u' == str)
		return (conv_u(va_arg(list_a, unsigned int)));
	if ('x' == str)
		return (conv_x(va_arg(list_a, int)));
	if ('X' == str)
		return (conv_xc(va_arg(list_a, int)));
	if ('%' == str)
	{
		return (conv_pp());
		//printf("<>");
		//return (0);
	}
	return (0);							//@@todo error handling?
}

int	ft_printf(const char *s, ...)
{
	size_t	string_i;		// Counter for the input string iteration
	size_t	arg_i;			// Counter for the function arguments lenght
	va_list	list_a;			// Pointer to the argument list

	va_start(list_a, s);
	string_i = 0;			// Init counter to 0 eg. the start of
	arg_i = 0;
	while(s[string_i] != '\0')
	{
		if (ft_printf_is_modifier(s, string_i) != 0)
		{
			arg_i += ft_printf_handle_argument(s[string_i+1], list_a);
			string_i++;
		}
		else
			write(1, &s[string_i], 1);	
		string_i++;
	}
	va_end(list_a);
//printf("\narg counter: %d\n",ft_printf_count_args(s));
//printf("\narg_i counter: %ld\n",arg_i);
//printf("\nstring counter: %ld\n",string_i);
printf("\nOutput char counter: %ld\n",string_i-ft_printf_count_args(s)*2+arg_i);
	return (string_i-ft_printf_count_args(s)*2+arg_i);
}
