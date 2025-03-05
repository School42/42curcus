/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:33:59 by talin             #+#    #+#             */
/*   Updated: 2025/03/05 13:45:36 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!(ac == 5 || ac == 6))
		return (ft_exit("Need to run with four or five args!"), 1);
	if (ft_init_data(av, &data))
		return (1);
	data.t_start = ft_get_current_time() + (data.num_philo * 10);
	if (ft_start_simu(&data))
		return (ft_exit_free("Simulation error!", &data), 1);
	ft_closing_simu(&data);
	return (0);
}
