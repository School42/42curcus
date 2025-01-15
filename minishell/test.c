/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:30:12 by talin             #+#    #+#             */
/*   Updated: 2025/01/15 14:35:44 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_redirection {
    char *file;
    int type;  // 0 for input redirection (<), 1 for output redirection (>), 2 for append redirection (>>)
} t_redirection;

typedef struct s_command {
    char *cmd;  // Command (e.g., "echo")
    char **args;  // Arguments (e.g., ["hello", "world"])
    t_redirection *input_redirect;  // Input redirection
    t_redirection *output_redirect; // Output redirection
    struct s_command *next;  // Next command in a pipeline
} t_command;

void add_argument_to_command(t_command *cmd, char *arg) {
	printf("^^^\n");
    if (!cmd->args) {
		printf("&&&\n");
        cmd->args = malloc(sizeof(char *) * 2);  // Allocate space for 1 argument + NULL terminator
        if (!cmd->args) {
            perror("malloc");
            return;
        }
        cmd->args[0] = NULL;  // NULL-terminate the args array
    }
	printf("+++\n");
    // Find the current size of the args array
    int i = 0;
    while (cmd->args[i] != NULL) {
        i++;
    }

    // Resize the array to hold one more argument
    char **new_args = realloc(cmd->args, sizeof(char *) * (i + 2));  // +1 for the new argument, +1 for the NULL terminator
    if (!new_args) {
        perror("realloc");
        return;
    }
    cmd->args = new_args;

    // Allocate memory for the new argument and copy the token into it
    cmd->args[i] = strdup(arg);
    if (!cmd->args[i]) {
        perror("strdup");
        return;
    }
	printf("---\n");
    cmd->args[i + 1] = NULL;  // Null-terminate the arguments array
}

// Function to initialize a new command
t_command *create_command(char *cmd) {
    t_command *new_cmd = malloc(sizeof(t_command));
    if (!new_cmd) {
        perror("malloc");
        return NULL;
    }

    new_cmd->cmd = strdup(cmd);  // Duplicate the command string
    new_cmd->args = NULL;         // Initialize args to NULL
    new_cmd->input_redirect = NULL;
    new_cmd->output_redirect = NULL;
    new_cmd->next = NULL;

    return new_cmd;
}

// Function to handle redirection
void handle_redirection(t_command *cmd, char *token) {
    if (token[0] == '<') {
        // Handle input redirection
        cmd->input_redirect = malloc(sizeof(t_redirection));
        cmd->input_redirect->file = strdup(token + 1);  // Skip the '<' character
        cmd->input_redirect->type = 0;  // Input redirection
    } else if (token[0] == '>') {
        // Handle output redirection
        cmd->output_redirect = malloc(sizeof(t_redirection));
        cmd->output_redirect->file = strdup(token + 1);  // Skip the '>' character
        cmd->output_redirect->type = (token[1] == '>') ? 2 : 1;  // Append or overwrite
    }
}

// Main function for parsing
t_command *parse_tokens(char **tokens) {
    t_command *head = NULL;
    t_command *current = NULL;

    for (int i = 0; tokens[i] != NULL; i++) {
		printf("%d\n", i);
        if (strcmp(tokens[i], "|") == 0) {
            // Create a new command for pipeline
            current->next = create_command(tokens[++i]);  // Skip the pipe and start a new command
            printf("testing\n");
			current = current->next;
        } else if (strcmp(tokens[i], "<") == 0 || strcmp(tokens[i], ">") == 0 || strcmp(tokens[i], ">>") == 0) {
            // Handle redirection
            handle_redirection(current, tokens[i]);
        } else {
            // Add argument to current command
			printf("...\n");
            add_argument_to_command(current, tokens[i]);
			printf(".....\n");
        }
    }

    return head;
}

int main() {
    // Sample tokens from a simple input: "echo hello > out.txt | cat < in.txt"
    char *tokens[] = {"echo", "hello", ">", "out.txt", "|", "cat", "<", "in.txt", NULL};
	printf("hi\n");
    t_command *parsed_commands = parse_tokens(tokens);
	printf("test\n");
    // Output parsed commands for testing
    t_command *cmd = parsed_commands;
	printf("hello\n");
    while (cmd) {
        printf("Command: %s\n", cmd->cmd);
        for (int i = 0; cmd->args[i] != NULL; i++) {
            printf("  Arg %d: %s\n", i, cmd->args[i]);
        }
        if (cmd->input_redirect) {
            printf("  Input redirect: %s\n", cmd->input_redirect->file);
        }
        if (cmd->output_redirect) {
            printf("  Output redirect: %s\n", cmd->output_redirect->file);
        }
        cmd = cmd->next;
    }

    return 0;
}
