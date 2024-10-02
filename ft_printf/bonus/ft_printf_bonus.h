/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:54:46 by talin             #+#    #+#             */
/*   Updated: 2024/10/02 15:40:59 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //remove this later

typedef struct t_format
{
	int		plus;
	int		minus;
	int		space;
	int		zero;
	int		dot;
	int		width;
	int		precision;
	int		neg_prec;
	int		sharp;
	char	specifier;
}	t_format;

# define SPECIFIER	"cspdiuxX%"
# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"

int			ft_printf(const char *str, ...);
char		*ft_strchr(char *s, int c);
int			ft_isdigit(int c);
int			ft_atoi(char *str);
t_format	ft_newformat(void);
int			ft_print_format(t_format new, va_list ptr);
int			ft_strlen(char *str);
int			ft_putnstr(char *str, int size);
int			ft_putnchar(int c, int size);
char		*ft_strdup(char *s);
int			ft_printf_str(t_format new, va_list ptr);
int			ft_printf_char(t_format new, va_list ptr);
int			ft_putchar(char c);
int			ft_parse(char *str, va_list ptr);
int			ft_printf_int(t_format new, va_list ptr);
char		ft_sign(t_format new, int neg);
char		ft_usign(t_format new);
int			ft_printf_uint(t_format new, va_list ptr);
int			ft_printf_ptr(t_format new, va_list ptr);
int			ft_recursive_hex(t_format new, size_t n, size_t i);
int			ft_nbrlen(size_t n);
int			ft_printf_hex(t_format new, va_list ptr);
#endif