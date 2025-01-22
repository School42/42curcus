/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:54:59 by talin             #+#    #+#             */
/*   Updated: 2025/01/22 16:25:46 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


char *get_env_value(char *env[], const char *var_name)
{
    for (int i = 0; env[i]; i++) {
        if (strncmp(env[i], var_name, strlen(var_name)) == 0 && env[i][strlen(var_name)] == '=') {
            return &env[i][strlen(var_name) + 1];
        }
    }
    return NULL;
}

char *expand_variable(char *input, char **env)
{
    char *expanded_str = malloc(strlen(input) + 1);
    if (!expanded_str) {
        perror("malloc");
        return NULL;
    }
    char *ptr = input;
    char *output_ptr = expanded_str;
    int inside_single_quote = 0;
    int inside_double_quote = 0;
    while (*ptr) {
        if (*ptr == '\'' && !inside_double_quote) {
            inside_single_quote = !inside_single_quote;
            *output_ptr = *ptr;
            output_ptr++;
            ptr++;
            continue;
        }
        if (*ptr == '\"' && !inside_single_quote) {
            inside_double_quote = !inside_double_quote;
            *output_ptr = *ptr;
            output_ptr++;
            ptr++;
            continue;
        }
        if (*ptr == '$' && !inside_single_quote) {
            ptr++;
            char var_name[256];
            int var_index = 0;
            while ((*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= 'a' && *ptr <= 'z') || (*ptr >= '0' && *ptr <= '9') || *ptr == '_') {
                var_name[var_index++] = *ptr++;
            }
            var_name[var_index] = '\0';
            char *var_value = get_env_value(env, var_name);
            if (var_value) {
                strcpy(output_ptr, var_value);
                output_ptr += strlen(var_value);
            }
        } else {
            *output_ptr = *ptr;
            output_ptr++;
            ptr++;
        }
    }
    *output_ptr = '\0';
    return expanded_str;
}

void parameter_expansion(t_command *commands, char **env)
{
    if (commands->cmd) {
        char *expanded_cmd = expand_variable(commands->cmd, env);
        if (expanded_cmd) {
            free(commands->cmd);
            commands->cmd = expanded_cmd;
        }
    }
    for (int i = 0; commands->args && commands->args[i]; i++) {
        char *expanded_arg = expand_variable(commands->args[i], env);
        if (expanded_arg) {
            free(commands->args[i]);
            commands->args[i] = expanded_arg;
        }
    }
    if (commands->infile && commands->infile->file_name) {
        char *expanded_infile = expand_variable(commands->infile->file_name, env);
        if (expanded_infile) {
            free(commands->infile->file_name);
            commands->infile->file_name = expanded_infile;
        }
    }
    if (commands->outfile && commands->outfile->file_name) {
        char *expanded_outfile = expand_variable(commands->outfile->file_name, env);
        if (expanded_outfile) {
            free(commands->outfile->file_name);
            commands->outfile->file_name = expanded_outfile;
        }
    }
}
