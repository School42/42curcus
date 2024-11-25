/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:31:25 by talin             #+#    #+#             */
/*   Updated: 2024/11/24 10:05:59 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_data
{
	int				num_philo;
	int				num_fork;
	time_t			t_die;
	time_t			t_eat;
	time_t			t_sleep;
	time_t			t_start;
	int				num_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}	t_data;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			t_ate;
	time_t		last_dine;
	t_data		*data;
}	t_philo;


int		ft_atoi(char *str);
void	ft_exit(char *str);
int		ft_strlen(char *str);
#endif