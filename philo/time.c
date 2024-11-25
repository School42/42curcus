#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

time_t	ft_get_current_time(void)
{
	time_t	x;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	x = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (x);
}

int main() {
	struct timeval current_time;
	time_t x;
	while (1)
	{
		x = ft_get_time();
	  	printf("x: %zu\n", x);
	}
}
