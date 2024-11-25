#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	struct timeval current_time;
	while (1)
	{
		gettimeofday(&current_time, NULL);
		printf("seconds : %ld\nmicro seconds : %ld\n",
		current_time.tv_sec, current_time.tv_usec);
		usleep(1000000);
	}
  return 0;
}