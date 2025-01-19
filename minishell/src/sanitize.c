/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:32:21 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/18 13:35:12 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int check_unclosed_quotes(const char *token) {
    int single_quote = 0, double_quote = 0;

    for (size_t i = 0; token[i]; i++) {
        if (token[i] == '\'' && double_quote == 0)
            single_quote = !single_quote;
        else if (token[i] == '"' && single_quote == 0)
            double_quote = !double_quote;
    }
    return (single_quote || double_quote);
}

int is_valid_redirection(const char *token, const char *next_token) {
    if (strcmp(token, "<") == 0 || strcmp(token, ">") == 0 ||
        strcmp(token, "<<") == 0 || strcmp(token, ">>") == 0) {
        if (!next_token || next_token[0] == '\0' || strcmp(next_token, "|") == 0)
            return 0;
    }
    return 1;
}

int sanitize_tokens(char **tokens) {
    for (int i = 0; tokens[i]; i++) {
        if (check_unclosed_quotes(tokens[i])) {
            fprintf(stderr, "Error: Unclosed quotes in token '%s'\n", tokens[i]);
            return ERROR_INVALID_QUOTE;
        }
        if (strcmp(tokens[i], "<") == 0 || strcmp(tokens[i], ">") == 0 ||
            strcmp(tokens[i], "<<") == 0 || strcmp(tokens[i], ">>") == 0) {
            if (!is_valid_redirection(tokens[i], tokens[i + 1])) {
                fprintf(stderr, "Error: Invalid redirection near token '%s'\n", tokens[i]);
                return ERROR_INVALID_REDIRECTION;
            }
        }
        if (strcmp(tokens[i], "|") == 0) {
            if (i == 0 || !tokens[i + 1] || strcmp(tokens[i + 1], "|") == 0) {
                fprintf(stderr, "Error: Invalid pipe placement near token '%s'\n", tokens[i]);
                return ERROR_INVALID_PIPE;
            }
        }
    }
    return 0;
}
