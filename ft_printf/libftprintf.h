/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:30:22 by talin             #+#    #+#             */
/*   Updated: 2024/09/10 10:59:40 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_usize(unsigned int n);
char	*ft_uitoa(unsigned int n);
char	*ft_itoa(int n);
size_t	ft_size(int n);
void	ft_hex(unsigned int num, int n);
void	ft_put(unsigned long nbr);
int		ft_putuint(unsigned int n);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_printf(const char *format, ...);
int		ft_hex_len(unsigned int num);
int		ft_puthex(unsigned int num, int n);
int		ft_len_ptr(unsigned long nbr);
int		ft_putptr(unsigned long ptr);
#endif