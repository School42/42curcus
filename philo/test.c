/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:39:08 by talin             #+#    #+#             */
/*   Updated: 2024/11/22 15:09:56 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#ifndef NUM_PHILO
# define NUM_PHILO 12
#endif

typedef struct s_data
{
	int				mails;
	pthread_mutex_t	mutex;
}	t_data;

void	*routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = -1;
	while (++i < 2000)
	{
		pthread_mutex_lock(&data->mutex);
		data->mails++;
		pthread_mutex_unlock(&data->mutex);
	}
	return (NULL);
}

int	main(void)
{
	t_data			data;
	int				i;
	pthread_t		th[NUM_PHILO];

	data.mails = 0;
	i = -1;
	pthread_mutex_init(&data.mutex, NULL);
	while (++i < NUM_PHILO)
	{
		if ((pthread_create(&th[i], NULL, &routine, &data) != 0))
		{
			perror("failed to create thread!");
			return (1);
		}
	}
	i = -1;
	while (++i < NUM_PHILO)
	{
		if ((pthread_join(th[i], NULL)) != 0)
		{
			perror("failed to join threads!");
			return (2);
		}
	}
	pthread_mutex_destroy(&data.mutex);
	printf("mails: %d\n", data.mails);
	return (0);
}
