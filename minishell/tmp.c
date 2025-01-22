#include <stdio.h>
#include <string.h>

// Declare the extern variable for environment
extern char **environ;

int main() {
    char **env = environ;

    // Iterate through all environment variables
    while (*env) {
        // Check if the current variable starts with "PATH="
        if (strncmp(*env, "PATH=", 5) == 0) {
            printf("%s\n", *env);
            break; // PATH found, exit the loop
        }
        env++;
    }

    return 0;
}
