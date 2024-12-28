#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <semaphore.h>
#include <sys/wait.h>

#define NUM_PHILO 5
#define COUNTER_FILE "shared_counter.txt"

typedef struct s_data
{
	sem_t	*print_word;
	sem_t	*count_sem;
}	t_data;

typedef struct s_philo
{
	t_data	*data;
	pid_t	pid;
}	t_philo;

void ft_update_counter(const char *filename, int increment)
{
	int fd;
	int count;

	// Open the file for reading and writing
	fd = open(filename, O_RDWR);
	if (fd < 0)
	{
		perror("open");
		exit(1);
	}

	// Read the current count
	if (read(fd, &count, sizeof(int)) != sizeof(int))
		count = 0; // If file is empty or corrupted, initialize to 0

	// Increment the count
	count += increment;

	// Write back the updated count
	lseek(fd, 0, SEEK_SET);
	if (write(fd, &count, sizeof(int)) != sizeof(int))
	{
		perror("write");
		close(fd);
		exit(1);
	}

	close(fd);
}

void ft_routine(t_philo *philo, int i)
{
	sem_wait(philo->data->print_word);
	printf("philo-%d acquires semaphore\n", i);
	sem_post(philo->data->print_word);

	sem_wait(philo->data->count_sem);
	ft_update_counter(COUNTER_FILE, 1); // Increment the shared counter
	sem_post(philo->data->count_sem);
}

void ft_do_something(t_data *data, t_philo *philo)
{
	int i = 0;

	while (i < NUM_PHILO)
	{
		philo[i].data = data;
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			ft_routine(&philo[i], i);
			exit(0);
		}
		i++;
	}

	// Wait for all child processes
	for (i = 0; i < NUM_PHILO; i++)
		waitpid(philo[i].pid, NULL, 0);
}

int main(void)
{
	t_data data;
	t_philo *philo;

	// Initialize counter file
	int fd = open(COUNTER_FILE, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd < 0)
	{
		perror("open");
		return 1;
	}
	int initial_count = 0;
	if (write(fd, &initial_count, sizeof(int)) != sizeof(int))
	{
		perror("write");
		close(fd);
		return 1;
	}
	close(fd);

	// Initialize semaphores
	sem_unlink("print_word");
	sem_unlink("count_sem");
	data.print_word = sem_open("print_word", O_CREAT, 0600, 1);
	data.count_sem = sem_open("count_sem", O_CREAT, 0600, 1);
	if (data.print_word == SEM_FAILED || data.count_sem == SEM_FAILED)
	{
		perror("sem_open");
		return 1;
	}

	// Allocate philosophers
	philo = malloc(sizeof(t_philo) * NUM_PHILO);
	if (!philo)
		return 1;

	ft_do_something(&data, philo);

	// Print the final count
	fd = open(COUNTER_FILE, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return 1;
	}
	int final_count;
	if (read(fd, &final_count, sizeof(int)) != sizeof(int))
	{
		perror("read");
		close(fd);
		return 1;
	}
	close(fd);

	printf("Final count: %d\n", final_count);

	// Cleanup
	sem_close(data.print_word);
	sem_close(data.count_sem);
	sem_unlink("print_word");
	sem_unlink("count_sem");
	free(philo);

	// Remove the counter file
	unlink(COUNTER_FILE);

	return 0;
}
