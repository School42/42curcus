/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:33:59 by talin             #+#    #+#             */
/*   Updated: 2024/12/09 12:35:51 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!(ac == 5 || ac == 6))
		ft_exit("Need to run with four or five args!");
	if (ft_init_data(av, ac, &data))
		ft_exit_free("Initialization error!", &data);
	data.t_start = ft_get_current_time() + (data.num_philo * 10);
	if (ft_start_simu(&data))
		ft_exit_free("Simulation error!", &data);
	ft_closing_simu(&data);
	return (0);
}
