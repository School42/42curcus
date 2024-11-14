/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:35:22 by talin             #+#    #+#             */
/*   Updated: 2024/11/14 13:35:29 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

typedef struct s_cmd {
    char **args;     // Command arguments (cmd + params)
    char *path;      // Full path to executable
} t_cmd;

void error_exit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void execute_cmd(t_cmd *cmd, int input_fd, int output_fd) {
    // Redirect stdin if input_fd is valid
    if (input_fd != STDIN_FILENO) {
        if (dup2(input_fd, STDIN_FILENO) == -1)
            error_exit("dup2 input");
        close(input_fd);
    }
    
    // Redirect stdout if output_fd is valid
    if (output_fd != STDOUT_FILENO) {
        if (dup2(output_fd, STDOUT_FILENO) == -1)
            error_exit("dup2 output");
        close(output_fd);
    }
    
    // Execute command
    execve(cmd->path, cmd->args, NULL);
    error_exit("execve");
}

void run_pipeline(t_cmd *cmds, int cmd_count, char *infile, char *outfile) {
    int i;
    int pipes[2];
    int prev_pipe = -1;
    pid_t *pids = malloc(sizeof(pid_t) * cmd_count);
    
    if (!pids)
        error_exit("malloc");

    // Open input file
    int input_fd = open(infile, O_RDONLY);
    if (input_fd == -1)
        error_exit("open input");

    // Open output file
    int output_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1)
        error_exit("open output");

    // Execute commands in pipeline
    for (i = 0; i < cmd_count; i++) {
        // Create pipe for all but last command
        if (i < cmd_count - 1) {
            if (pipe(pipes) == -1)
                error_exit("pipe");
        }

        // Fork process
        pids[i] = fork();
        if (pids[i] == -1)
            error_exit("fork");

        if (pids[i] == 0) {  // Child process
            // Set up input
            int in_fd = (i == 0) ? input_fd : prev_pipe;
            
            // Set up output
            int out_fd = (i == cmd_count - 1) ? output_fd : pipes[1];
            
            // Close unused pipe ends
            if (i < cmd_count - 1)
                close(pipes[0]);
            
            execute_cmd(&cmds[i], in_fd, out_fd);
        }
        
        // Parent process
        if (i > 0)
            close(prev_pipe);
        if (i < cmd_count - 1) {
            close(pipes[1]);
            prev_pipe = pipes[0];
        }
    }

    // Close remaining file descriptors
    close(input_fd);
    close(output_fd);

    // Wait for all child processes
    for (i = 0; i < cmd_count; i++) {
        int status;
        waitpid(pids[i], &status, 0);
    }

    free(pids);
}

// Example usage:
int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s infile cmd1 cmd2 ... outfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int cmd_count = argc - 3;  // Number of commands
    t_cmd *cmds = malloc(sizeof(t_cmd) * cmd_count);
    if (!cmds)
        error_exit("malloc");

    // Setup commands (simplified - you'll need to implement proper path resolution)
    for (int i = 0; i < cmd_count; i++) {
        cmds[i].path = argv[i + 2];  // Simplified - should resolve full path
        cmds[i].args = &argv[i + 2];  // Simplified - should properly split arguments
    }

    run_pipeline(cmds, cmd_count, argv[1], argv[argc - 1]);
    free(cmds);
    return 0;
}