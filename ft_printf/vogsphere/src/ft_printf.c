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

#include "../inc/ft_printf.h"
#include <stdio.h>

/* arg0 string gets written out
 * @return the lenght outputted
 */
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

/* @return the number of modifiers in the format string
 */
int	ft_printf_count_args(const char *s)
{
	size_t	i;
	size_t	arg_c;

	i = 0;
	arg_c = 0;
	while (s[i] != '\0')
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

/* @return 1 if index i of string s is a modifier string
 * How? Current position is % sign and next char belongs to the subset of strs
 */
int	ft_printf_is_modifier(const char *s, size_t i)
{
	if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]) != NULL)
	{
		return (1);
	}
	return (0);
}

/* @arg0 is the modifier char, @arg1 is list of arguments and route conv funcs
 * @return value is the lenght of argument that was being printed
 */
size_t	ft_printf_handle_argument(char str, va_list list_a)
{
	if ('c' == str)
		return (conv_c(va_arg(list_a, int)));
	if ('s' == str)
		return (conv_s(va_arg(list_a, char *)));
	if ('p' == str)
		return (conv_p(va_arg(list_a, void *)));
	if ('d' == str || 'i' == str)
		return (conv_di(va_arg(list_a, int)));
	if ('u' == str)
		return (conv_u(va_arg(list_a, unsigned int)));
	if ('x' == str)
		return (conv_x(va_arg(list_a, int)));
	if ('X' == str)
		return (conv_xc(va_arg(list_a, int)));
	if ('%' == str)
		return (write(1, &"%", 1));
	return (0);
}

/* Main printf function.
 *
 * Iterate input format string:
 * 	- count arguments for return value(in the end)
 * 	- if string specifies a value of a variable to be printef out (% sign)
 * 		then do that.
 * 	- if not a special identifier then just print that
 * 	- count all the printed characters one by one
 * 	@return the number of characters that were printed out
 */
int	ft_printf(const char *s, ...)
{
	size_t	string_i;
	size_t	arg_i;
	va_list	list_a;

	va_start(list_a, s);
	string_i = 0;
	arg_i = 0;
	while (s[string_i] != '\0')
	{
		if (ft_printf_is_modifier(s, string_i) != 0)
		{
			arg_i += ft_printf_handle_argument(s[string_i + 1], list_a);
			string_i++;
		}
		else
			write(1, &s[string_i], 1);
		string_i++;
	}
	va_end(list_a);
	return (string_i - ft_printf_count_args(s) * 2 + arg_i);
}
