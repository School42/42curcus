/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:33:59 by talin             #+#    #+#             */
/*   Updated: 2024/11/25 15:28:25 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		ft_exit("Need to run with four or five args!");
	ft_init_data(av, ac, &data);
	data.t_start = ft_get_current_time() + (data.num_philo * 20);
	pthread_mutex_lock(&data.mutex_log);
	printf("Simulation started...\n");
	pthread_mutex_unlock(&data.mutex_log);
	ft_start_simu(&data);
}
