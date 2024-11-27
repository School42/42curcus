#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>

#define SEM_NAME "/sequential_semaphore"

int main() {
    int count = 0;
    
    // Semaphore for sequential processing
    sem_t *seq_sem = sem_open(SEM_NAME, O_CREAT, 0644, 1);
    
    if (seq_sem == SEM_FAILED) {
        perror("sem_open failed");
        exit(1);
    }

    for (int i = 0; i < 5; i++) {
        // Wait for previous process to complete
        sem_wait(seq_sem);

        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }

        if (pid == 0) {
            // Child process
            // Increment count
            count++;
            
            printf("Process %d incrementing: %d\n", getpid(), count);
            
            // Signal parent to continue next process
            sem_post(seq_sem);
            
            exit(count);
        }
    }

    // Parent process waits for all children
    int total_count = 0;
    for (int i = 0; i < 5; i++) {
        int child_status;
        wait(&child_status);
        
        if (WIFEXITED(child_status)) {
            // Accumulate the individual increments
            total_count += WEXITSTATUS(child_status);
        }
    }

    printf("Final total count: %d\n", total_count);

    // Cleanup
    sem_close(seq_sem);
    sem_unlink(SEM_NAME);

    return 0;
}