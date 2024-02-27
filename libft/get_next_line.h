/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:29:46 by andefern          #+#    #+#             */
/*   Updated: 2024/01/23 13:34:25 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/syslimits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

size_t	ft_len(const char *s);
char	*ft_schr(char *s, int c);
char	*ft_sjoin(char *s1, char *s2);
char	*ft_readfd(char *str, int fd);
char	*newline(char *temp);
char	*ft_static(char	*str);
char	*get_next_line(int fd);

#endif
