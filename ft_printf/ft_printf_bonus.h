/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:54:46 by talin             #+#    #+#             */
/*   Updated: 2024/09/25 15:46:43 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>

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
#endif