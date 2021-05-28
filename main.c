/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:29:33 by kmottus           #+#    #+#             */
/*   Updated: 2021/02/25 14:38:04 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "libft.h"

int	main(void)
{		
	printf("Hello! This is the main the test my Libft 42 Project.\n");
	printf("No no no no no no no no no no no no no there's no limits.\n");

//	roll();
	printf("\n");
//	rock();

printf("\nFT_STRLCPY \n");//qq

	char	qq1[] = "Tererererere";
	char	ww1[] = "Trololoo";
	int	sl1;
	char	oo1[] = "Tererererere";
	char	pp1[] = "Trololoo";
	int	fl1;

	int	sq1, so1;	//Sizes of
	
	sl1 = 0;
	fl1 = 0;

	sq1 = sizeof(qq1);
	so1 = sizeof(oo1);

	printf("\npreC:%s-%s\t|%s-%s\t>sz:%d;%d",qq1,ww1,oo1,pp1,sq1,so1);

	sl1 = strlcpy(		qq1, ww1, sq1);
	fl1 = ft_strlcpy(	oo1, pp1, so1);

	sq1 = sizeof(qq1);
	so1 = sizeof(oo1);
	printf("\npost:%s-\t|%s-\t\trt>%d-%dsz:%d;%d",qq1,oo1,sl1,fl1,sq1,so1);

	printf("\n");
	printf("\n");
	printf("\n");
	printf("Test print");

	int ch;

	for (ch = 0; ch <= 130; ch++)
	{
		printf("%d	", ch);
		if (isprint(ch))
			printf("yes %c\n", ch);
		else
			printf("no \n");
	}

	return (0);
}
