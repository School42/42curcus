/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:28:50 by talin             #+#    #+#             */
/*   Updated: 2025/01/20 15:31:06 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include "./include/minishell.h"

char *find_command_path(char *cmd) {
    char *path_env = getenv("PATH");
    char *path = strdup(path_env);
    char *token = strtok(path, ":");
    char *full_path = NULL;

    while (token) {
        full_path = malloc(strlen(token) + strlen(cmd) + 2);
        if (!full_path) {
            perror("malloc");
            free(path);
            return NULL;
        }
        sprintf(full_path, "%s/%s", token, cmd);
        if (access(full_path, X_OK) == 0) {
            free(path);
            return full_path;
        }
        free(full_path);
        token = strtok(NULL, ":");
    }

    free(path);
    return NULL;
}

void execute_single_command(t_command *cmd) {
    pid_t pid = fork();
    if (pid == 0) {
        if (cmd->infile) {
            int fd_in = open(cmd->infile->file_name, O_RDONLY);
            if (fd_in == -1) {
                perror("open infile");
                exit(EXIT_FAILURE);
            }
            dup2(fd_in, STDIN_FILENO);
            close(fd_in);
        }
        if (cmd->outfile) {
            int fd_out;
            if (cmd->outfile->redirect_type == 1)
                fd_out = open(cmd->outfile->file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
            else
                fd_out = open(cmd->outfile->file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd_out == -1) {
                perror("open outfile");
                exit(EXIT_FAILURE);
            }
            dup2(fd_out, STDOUT_FILENO);
            close(fd_out);
        }
        char *cmd_path = find_command_path(cmd->cmd);
        if (!cmd_path) {
            fprintf(stderr, "Command not found: %s\n", cmd->cmd);
            exit(EXIT_FAILURE);
        }
        execve(cmd_path, cmd->args, environ);
        perror("execve");
        free(cmd_path);
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Command exited with status: %d\n", WEXITSTATUS(status));
        }
    } else {
        perror("fork");
    }
}

void execute_commands(t_command *commands) {
    t_command *current = commands;
    while (current) {
        execute_single_command(current);
        current = current->next;
    }
}
