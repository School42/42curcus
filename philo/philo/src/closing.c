/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:42:56 by talin             #+#    #+#             */
/*   Updated: 2025/03/05 13:41:52 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_closing_simu(t_data *data)
{
	int	i;

	i = -1;
	if (data->fork)
	{
		while (++i < data->num_philo)
			pthread_mutex_destroy(&data->fork[i]);
		free(data->fork);
	}
	if (data->philos)
		free(data->philos);
	pthread_mutex_destroy(&data->mutex_dead);
	pthread_mutex_destroy(&data->mutex_last_meal);
	pthread_mutex_destroy(&data->mutex_log);
	pthread_mutex_destroy(&data->mutex_meal_count);
}

void	ft_exit_free(char *str, t_data *data)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	ft_closing_simu(data);
}
