/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:50:00 by kmottus           #+#    #+#             */
/*   Updated: 2022/06/16 09:50:00 by kmottus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<stdarg.h>
#ifndef FT_GNL_H
# define FT_GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# define FD_MAX 4096

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);

char	*get_next_line(int fd);

#endif
