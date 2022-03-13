/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:30:00 by kmottus           #+#    #+#             */
/*   Updated: 2022/03/08 14:30:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_printf(const char *, ...);

int	main(void)
{
	char			q;		// %c a character
	char			*w;		// %s string
	void			*e;		// %p base 16 pointer
	int				r;		// %d base 10 decimal
	int				t;		// %i base 10 integer
	unsigned int	y;		// %u unsigned decimal/int(!?)
	int				hx_u;	// %x base 16 low-case
	int				hx_i;	// %X base 16 hi-case
	char	*instring;

	q = 'w';
	w = "why?";
	e = &w;
	r = 13.37;
	t = -27;
	y = -369;
	hx_u = 29;
	hx_i = 31;
	//instring = "%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\n";
	instring = "%c\n%X\n%%\n";

	printf("Hello from ft_printf tester\n\n");

	////OG matching call:	
	//printf(instring, q, w, e, r, t, y, hx_u, hx_i);
	////more args is not an arg, UBehaviour?
	//printf(instring, q, w, e, r, t, y, hx_u, hx_i, r);

	//ft_printf("%%Hello: %s.", 1, 4, 3, 2);
	//ft_printf(instring, 1, 4, 3, 2);
	ft_printf(instring, q, w, e, r, t, y, hx_u, hx_i);

	printf("\n");
	return(0);
}
