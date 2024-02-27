/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:03:24 by andefern          #+#    #+#             */
/*   Updated: 2024/02/19 10:51:16 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

//UTILS
void	pf_putchar(char c);
void	pf_putstr(char *s);
int		pf_putnbr(int n);
int		pf_hex(unsigned long n, int up_or_low);
int		pf_retstr(char *str);
int		pf_uputnbr(unsigned int n);
size_t	pf_strlen(const char *s);

//MAIN
int		pf_support(va_list things, char c);
int		ft_printf(const char *print, ...);

#endif