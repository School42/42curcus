/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:28:03 by talin             #+#    #+#             */
/*   Updated: 2024/11/26 14:05:24 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_check_philo_dead(t_philo *philo)
{
	time_t	x;

	pthread_mutex_lock(&philo->data->mutex_last_meal);
	x = ft_get_current_time() - philo->last_dine;
	pthread_mutex_unlock(&philo->data->mutex_last_meal);
	if (x >= philo->data->t_die)
	{
		pthread_mutex_lock(&philo->data->mutex_dead);
		philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->mutex_dead);
		usleep(1000);
		monitor_msg(philo, DIE);
		return (1);
	}
	return (0);
}

int	ft_check_dead(t_data *data)
{
	int	i;
	int	status;

	status = 1;
	i = -1;
	while (++i < data->num_philo)
	{
		if (ft_check_philo_dead(&data->philos[i]))
			return (1);
		if (data->num_eat)
		{
			pthread_mutex_lock(&data->mutex_meal_count);
			if (data->philos[i].t_ate < data->num_eat)
				status = 0;
			pthread_mutex_unlock(&data->mutex_meal_count);
		}
	}
	if (data->num_eat && status)
	{
		pthread_mutex_lock(&data->mutex_dead);
		data->dead = 1;
		pthread_mutex_unlock(&data->mutex_dead);
		return (1);
	}
	return (0);
}

void	*life(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (ft_get_current_time() < data->t_start)
		continue ;
	while (!ft_check_end(data))
	{
		if (ft_check_dead(data))
			break ;
		usleep(1000);
	}
	return (NULL);
}

int	ft_start_simu(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, \
		&routine, &data->philos[i]) != 0)
			return (1);
	}
	if (pthread_create(&data->life, NULL, &life, data) != 0)
		return (1);
	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (1);
	}
	if (pthread_join(data->life, NULL) != 0)
		return (1);
	return (0);
}
