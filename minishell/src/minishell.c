/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:35:12 by talin             #+#    #+#             */
/*   Updated: 2025/01/18 13:37:41 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_lexer	*tokenize(char *input)
{
	t_lexer	*lexer;
	char	**new_tokens;
	int		i;

	lexer = malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->tokens = NULL;
	lexer->token_count = 0;
	if (!ft_tokenize_four(lexer, input))
		return (NULL);
	new_tokens = malloc(sizeof(char *) * (lexer->token_count + 1));
	if (!new_tokens)
		return (free_lexer(lexer), NULL);
	i = -1;
	while (++i < lexer->token_count)
		new_tokens[i] = lexer->tokens[i];
	free(lexer->tokens);
	lexer->tokens = new_tokens;
	lexer->tokens[lexer->token_count] = NULL;
	return (lexer);
}

int	main(void)
{
	char		*input;
	t_lexer		*lexer;
	t_command	*commands;
	int		i;

	input = readline("minishell > ");
	input[ft_strcspn(input, "\n")] = '\0';
	lexer = tokenize(input);
	
	if (lexer)
	{
		printf("Tokens:\n");
		i = 0;
		while (lexer->tokens[i])
		{
			printf("[%s]\n", lexer->tokens[i]);
			i++;
		}
		if (sanitize_tokens(lexer->tokens) != 0)
		{
			free_lexer(lexer);
			printf("Error\n");
			return (0);
		}
		// free_lexer(lexer);
	}
	commands = parse_tokens(lexer);

	if (commands) {
		print_commands(commands);
		free_commands(commands);
    }
	return (0);
}
