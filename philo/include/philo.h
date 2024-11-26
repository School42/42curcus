/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:31:25 by talin             #+#    #+#             */
/*   Updated: 2024/11/26 11:38:42 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>

typedef struct s_philo t_philo;

typedef struct s_data
{
	int				num_philo;
	time_t			t_die;
	time_t			t_eat;
	time_t			t_sleep;
	time_t			t_start;
	int				num_eat;
	int				dead;
	pthread_mutex_t	*fork;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	mutex_meal_count;
	pthread_mutex_t	mutex_log;
	pthread_mutex_t	mutex_last_meal;
	t_philo			*philos;
	pthread_t		life;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				t_ate;
	time_t			last_dine;
	t_data			*data;
}	t_philo;

enum
{
	TAKE_FORK = 1,
	DIE = 2,
	EAT = 3,
	SLEEP = 4,
	THINK = 5
};

time_t	ft_get_current_time(void);
int		ft_atoi(char *str);
void	ft_exit(char *str);
int		ft_strlen(char *str);
int		ft_init_data(char **av, int ac, t_data *data);
int		ft_init_mutex(t_data *data);
int		ft_init_philo(t_data *data);
void	ft_assign_forks(int i, t_philo *philo);
int		ft_check_end(t_data *data);
void	ft_wait(t_data *data, time_t num_time);
void	monitor_msg(t_philo *philo, int code);
void	*routine(void *arg);
void	*life(void *arg);
int		ft_start_simu(t_data *data);
void	ft_closing_simu(t_data *data);
void	ft_exit_free(char *str, t_data *data);
#endif