/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:33:59 by talin             #+#    #+#             */
/*   Updated: 2024/11/24 10:24:37 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*ft_init_philo(t_data *data)
{
}

t_data	*ft_init_data(char **av, int ac)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->num_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->num_fork = data->num_philo;
	if (ac == 6)
		data->num_eat = ft_atoi(av[5]);
	else
		data->num_eat = 0;
	data->philos = ft_init_philo(data);
	return (data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
		ft_exit("Need to run with four or five args!");
	data = NULL;
	data = ft_init_data(av, ac);
}
