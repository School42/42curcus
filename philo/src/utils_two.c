/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:18:20 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/25 16:04:20 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_exit(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

time_t	ft_get_current_time(void)
{
	time_t			x;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	x = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (x);
}

int	ft_check_end(t_data *data)
{
	int	x;

	x = 0;
	pthread_mutex_lock(&data->mutex_dead);
	x = data->dead;
	pthread_mutex_unlock(&data->mutex_dead);
	return (x);
}

void	ft_wait(t_data *data, time_t num_time)
{
	time_t	x;

	x = ft_get_current_time() + num_time;
	while (!ft_check_end(data) && ft_get_current_time() < x)
		usleep(500);
}

void	monitor_msg(t_philo *philo, int code)
{
	pthread_mutex_lock(&philo->data->mutex_log);
	if (ft_check_end(philo->data) && code != DIE)
		code = -1;
	if (code == EAT)
		printf("%010zu %d is eating\n", \
		ft_get_current_time() - philo->data->t_start, philo->id);
	else if (code == SLEEP)
		printf("%010zu %d is sleeping\n", \
		ft_get_current_time() - philo->data->t_start, philo->id);
	else if (code == THINK)
		printf("%010zu %d is thinking\n", \
		ft_get_current_time() - philo->data->t_start, philo->id);
	else if (code == DIE)
		printf("%010zu %d died\n", \
		ft_get_current_time() - philo->data->t_start, philo->id);
	else if (code == RIGHT_FORK)
		printf("%010zu %d has taken right fork\n", \
		ft_get_current_time() - philo->data->t_start, philo->id);
	else if (code == LEFT_FORK)
		printf("%010zu %d has taken left fork\n", \
		ft_get_current_time() - philo->data->t_start, philo->id);
	else if (code == WAIT)
		printf("%010zu %d is waiting for fork\n", \
		ft_get_current_time() - philo->data->t_start, philo->id);
	pthread_mutex_unlock(&philo->data->mutex_log);
}
