#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_PHILOSOPHERS 5

// Define a structure to hold the semaphores
struct Philosopher {
    sem_t *forks[NUM_PHILOSOPHERS];
    sem_t *output_mutex;
};

void philosopher(int id, struct Philosopher *philosopher_data) {
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        // Thinking
        sem_wait(philosopher_data->output_mutex);
        printf("Philosopher %d is thinking...\n", id);
        sem_post(philosopher_data->output_mutex);
        usleep(rand() % 1000000);  // Simulate thinking time

        // Hungry, trying to pick up forks
        sem_wait(philosopher_data->output_mutex);
        printf("Philosopher %d is hungry and tries to pick up forks...\n", id);
        sem_post(philosopher_data->output_mutex);

        // Pick up forks based on even or odd ID
        if (id % 2 == 0) {
            // Even philosophers: pick up left fork first
            // sem_wait(philosopher_data->forks[left]);
            // sem_wait(philosopher_data->forks[right]);
			usleep(1000);
        } else {
            // Odd philosophers: pick up right fork first
            sem_wait(philosopher_data->forks[right]);
            sem_wait(philosopher_data->forks[left]);
        }

        // Eating
        sem_wait(philosopher_data->output_mutex);
        printf("Philosopher %d is eating...\n", id);
        sem_post(philosopher_data->output_mutex);
        usleep(rand() % 1000000);  // Simulate eating time

        // Put down forks
        sem_post(philosopher_data->forks[left]);
        sem_post(philosopher_data->forks[right]);

        // Resting
        usleep(rand() % 1000000);  // Simulate resting time
    }
}

int main() {
    pid_t pid;
    struct Philosopher philosopher_data;
    char semaphore_name[20];

    // Initialize named semaphores for forks
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sprintf(semaphore_name, "/fork%d", i);
        philosopher_data.forks[i] = sem_open(semaphore_name, O_CREAT, 0644, 1);
        if (philosopher_data.forks[i] == SEM_FAILED) {
            perror("sem_open");
            exit(1);
        }
    }

    // Initialize a named semaphore for output mutex
    philosopher_data.output_mutex = sem_open("/output_mutex", O_CREAT, 0644, 1);
    if (philosopher_data.output_mutex == SEM_FAILED) {
        perror("sem_open output_mutex");
        exit(1);
    }

    // Create processes for philosophers
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pid = fork();
        if (pid == 0) {
            philosopher(i, &philosopher_data);  // Pass the philosopher data
            exit(0);  // End child process after finishing
        }
    }

    // Parent process waits for children (not necessary in this infinite loop scenario)
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        wait(NULL);  // Wait for each child (philosopher) process to finish
    }

    // Clean up semaphores
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sprintf(semaphore_name, "/fork%d", i);  // Use the semaphore name for unlinking
        sem_close(philosopher_data.forks[i]);
        sem_unlink(semaphore_name);  // Pass the semaphore name, not the pointer
    }
    sem_close(philosopher_data.output_mutex);
    sem_unlink("/output_mutex");

    return 0;
}
