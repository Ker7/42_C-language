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

#include "../inc/ft_printf.h"
#include <stdio.h>

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

	int 	us_cnt;
	int		og_cnt;

	q = 'w';
	w = "why?";
	e = &w;
	r = 13.37;
	t = -27;
	y = -369;
	hx_u = 29;
	hx_i = 31;

	instring = " %x %X %x ";

printf("Hello from testft_printf tester\n\n");
printf("Our program:\n");	

	us_cnt = ft_printf(instring, -30, -31, 0);

printf("\nOg program:\n");

	og_cnt = printf(instring, -30, -31, 0);

	printf("\n");	
	printf("\nCNT-in-og: %d---", og_cnt);	
	printf("\nCNT-in-us: %d---", us_cnt);	

return(0);

	ft_printf(instring, q, w, e, r, t, y, hx_u, hx_i);

	printf("\n");
	return(0);
}
