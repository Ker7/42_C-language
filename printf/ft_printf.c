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
#include <stdio.h>

void ft_printf_handle_modi(const char *s, size_t i)
{
	char	*mlist;

	mlist = "cspdiupxX%";//@ POOLELII!.w
	printf("\n\n@TodoStr: %s.c: %c.Modifiers: %s", s, s[i], mlist);

}

/* Return 1 if currently dealing with modifier */
int	ft_printf_is_modifier(const char *s, size_t i)
{
	if(s[i] != '\0')
	{
		if (s[i] == '%' && s[i] != '\\')
		{
			if (i == 0)
			{
				if (s[i + 1] != '%')
					return (1);
			}
			else if (s[i - 1] != '%' && s[i + 1] != '%')
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_printf_count_args(const char *s)
{
	size_t	i;		// string iterator
	size_t	arg_c;	// Argument count to be returned...

	i = 0;
	arg_c = 0;		// If we find % and the next&prev is not %, arg_c +one...
	while(s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (i == 0)
			{
				if (s[i + 1] != '%')
					arg_c++;
			}
			else if (s[i - 1] != '%' && s[i + 1] != '%')
				arg_c++;
		}
		i++;
	}
	return (arg_c);
}

int	ft_printf(const char *s, ...)
{
	size_t	string_i;		// Counter for the input string
//	size_t	arg_i;			// Counter for the function arguments
	size_t	slen;			// SUM Count of input string character
	size_t	vlen;			// SUM Count of function arguments
	va_list	list_a;			// Pointer to the argument list

	slen = ft_strlen(s);	// Lenght of input string PRE parse
	string_i = 0;			// Init counter to 0 eg. the start of

	vlen = ft_printf_count_args(s);
//	arg_i = 0;
	va_start(list_a, s);

	printf("\nStarting to parse input characters of %ld length...: \n", slen);
	printf("\ninput characters seem to have %ld count of arguments \n", vlen);
	while(s[string_i] != '\0')
	{
//		printf(" -- ");	// Ending LINE_BREAK
		printf("i:%lu;",string_i);		//string counter
		if ((int)s[string_i] == 10)
			printf("c:\\N;");	//character real
		else 
			printf("c:%c;",s[string_i]);	//character real
		printf("d:%d;",s[string_i]);		//character ASCII

//		if (s[string_i] == '%')
//			printf("- this might be a modifier! Watch out man!");
//		if (s[string_i] == ' ')
//			printf("- this is a space. Space out man!");
		if (ft_printf_is_modifier(s, string_i) == 1)
			ft_printf_handle_modi(s, string_i);
//		{
//			printf("Y\n");
//			string_i++;
//		}
//		else
//			printf("N\n");
			
		string_i++;
	}
	string_i = 0;	//Reset and start output
	while(s[string_i] != '\0')
	{

		string_i++;
	}
	va_end(list_a);
	return(0);
}
