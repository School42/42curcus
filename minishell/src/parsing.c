/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:27:03 by talin             #+#    #+#             */
/*   Updated: 2025/01/15 16:14:30 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_io_file *create_io_file(char *file_name, int redirect_type) {
    t_io_file *file = malloc(sizeof(t_io_file));
    if (!file)
        return NULL;
    file->file_name = strdup(file_name);
    file->redirect_type = redirect_type;
    return file;
}

t_command *create_command() {
    t_command *cmd = malloc(sizeof(t_command));
    if (!cmd)
        return NULL;
    cmd->cmd = NULL;
    cmd->args = NULL;
    cmd->infile = NULL;
    cmd->outfile = NULL;
    cmd->next = NULL;
    return cmd;
}

void add_argument(t_command *cmd, char *arg) {
    int arg_count = 0;
    if (cmd->args) {
        while (cmd->args[arg_count])
            arg_count++;
    }
    cmd->args = realloc(cmd->args, sizeof(char *) * (arg_count + 2));
    if (!cmd->args)
        return;
    cmd->args[arg_count] = strdup(arg);
    cmd->args[arg_count + 1] = NULL;
}

t_command *parse_tokens(t_lexer *lexer) {
    t_command *command_list = NULL;
    t_command *current_cmd = NULL;
    int i = 0;

    while (i < lexer->token_count) {
        char *token = lexer->tokens[i];

        if (strcmp(token, "|") == 0) {
            current_cmd->next = create_command();
            current_cmd = current_cmd->next;
        } else if (strcmp(token, "<") == 0 || strcmp(token, "<<") == 0) {
            if (i + 1 < lexer->token_count) {
                current_cmd->infile = create_io_file(lexer->tokens[++i], strcmp(token, "<") == 0 ? 1 : 2);
            } else {
                fprintf(stderr, "Syntax error: Missing input file after '%s'\n", token);
                return NULL;
            }
        } else if (strcmp(token, ">") == 0 || strcmp(token, ">>") == 0) {
            if (i + 1 < lexer->token_count) {
                current_cmd->outfile = create_io_file(lexer->tokens[++i], strcmp(token, ">") == 0 ? 1 : 2);
            } else {
                fprintf(stderr, "Syntax error: Missing output file after '%s'\n", token);
                return NULL;
            }
        } else {
            if (!current_cmd) {
                command_list = create_command();
                current_cmd = command_list;
            }
            if (!current_cmd->cmd) {
                current_cmd->cmd = strdup(token);
                add_argument(current_cmd, token);
            } else {
                add_argument(current_cmd, token);
            }
        }
        i++;
    }

    return command_list;
}

void	free_commands(t_command *cmd)
{
    t_command *temp;
    while (cmd) {
        temp = cmd;
        cmd = cmd->next;
        free(temp->cmd);
        if (temp->args) {
            for (int i = 0; temp->args[i]; i++)
                free(temp->args[i]);
            free(temp->args);
        }
        if (temp->infile) {
            free(temp->infile->file_name);
            free(temp->infile);
        }
        if (temp->outfile) {
            free(temp->outfile->file_name);
            free(temp->outfile);
        }
        free(temp);
    }
}

void	print_commands(t_command *cmd)
{
    while (cmd) {
        printf("Command: %s\n", cmd->cmd);
        if (cmd->args) {
            printf("Arguments:\n");
            for (int i = 0; cmd->args[i]; i++)
                printf("  %s\n", cmd->args[i]);
        }
        if (cmd->infile)
            printf("Input File: %s (Type: %d)\n", cmd->infile->file_name, cmd->infile->redirect_type);
        if (cmd->outfile)
            printf("Output File: %s (Type: %d)\n", cmd->outfile->file_name, cmd->outfile->redirect_type);
        cmd = cmd->next;
        printf("\n");
    }
}
