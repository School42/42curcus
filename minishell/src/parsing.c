/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:27:03 by talin             #+#    #+#             */
/*   Updated: 2025/01/16 12:26:39 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_io_file	*create_io_file(char *file_name, int redirect_type)
{
	t_io_file	*file;

	if (!file_name)
		return (NULL);
	file = malloc(sizeof(t_io_file));
	if (!file)
		return (NULL);
	file->file_name = ft_strdup(file_name);
	if (!file->file_name)
		return (free(file), NULL);
	file->redirect_type = redirect_type;
	return file;
}

t_command	*create_command(void)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return NULL;
	cmd->cmd = NULL;
	cmd->args = NULL;
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->next = NULL;
	return cmd;
}

void	add_argument(t_command *cmd, char *arg)
{
	int		arg_count;
	char	**new_args;
	int		i;

	arg_count = 0;
	if (!arg)
		return ;
	if (cmd->args)
		while (cmd->args[arg_count])
			arg_count++;
	new_args = malloc(sizeof(char *) * (arg_count + 2));
	if (!new_args)
		return ;
	i = -1;
	while (++i < arg_count)
		new_args[i] = cmd->args[i];
	free(cmd->args);
	new_args[arg_count] = ft_strdup(arg);
	if (!new_args[arg_count])
	{
		free(new_args);
		return ;
	}
	new_args[arg_count + 1] = NULL;
	cmd->args = new_args;
}

int	ft_parse_pipe(t_command **command_list, t_command **current_cmd)
{
	if (!*current_cmd)
	{
		fprintf(stderr, "Syntax error: Pipe '|' without a preceding command\n");
		return (free_commands(*command_list), 0);
	}
	(*current_cmd)->next = create_command();
	if (!(*current_cmd)->next)
	{
		fprintf(stderr, "Error: Failed to allocate memory for command\n");
		return (free_commands(*command_list), 0);
	}
	(*current_cmd) = (*current_cmd)->next;
	return (1);
}

int	ft_parse_in_red_two(t_command **command_list, t_command **current_cmd, int *i, t_lexer *lexer)
{
	char	*token;

	token = lexer->tokens[*i];
	if (ft_strcmp(token, "<") == 0)
	{
		(*current_cmd)->infile = create_io_file(lexer->tokens[++(*i)], REDIRECT_INPUT);
		if (!(*current_cmd)->infile)
		{
			fprintf(stderr, "Error: Failed to allocate memory for input redirection file\n");
			return (free_commands(*command_list), 0);
		}
	}
	else
	{
		(*current_cmd)->infile = create_io_file(lexer->tokens[++(*i)], REDIRECT_HEREDOC);
		if (!(*current_cmd)->infile)
		{
			fprintf(stderr, "Error: Failed to allocate memory for input redirection file\n");
			return (free_commands(*command_list), 0);
		}
	}
	return (1);
}

int	ft_parse_in_red(t_command **command_list, t_command **current_cmd, int *i, t_lexer *lexer)
{
	if (!*current_cmd)
	{
		*command_list = create_command();
		if (!*command_list)
		{
			fprintf(stderr, "Error: Failed to allocate memory for command\n");
			return (0);
		}
		*current_cmd = *command_list;
	}
	if (*i + 1 < lexer->token_count)
	{
		if (!ft_parse_in_red_two(command_list, current_cmd, i, lexer))
			return (0);
	}
	else
	{
		fprintf(stderr, "Syntax error: Missing input file\n");
		return (free_commands(*command_list), 0);
	}
	return (1);
}

int	ft_parse_out_red_two(t_command **command_list, t_command **current_cmd, int *i, t_lexer *lexer)
{
	char	*token;

	token = lexer->tokens[*i];
	if (ft_strcmp(token, ">") == 0)
	{
		(*current_cmd)->outfile = create_io_file(lexer->tokens[++(*i)], REDIRECT_OUTPUT);
		if (!(*current_cmd)->outfile)
		{
			fprintf(stderr, "Error: Failed to allocate memory for input redirection file\n");
			return (free_commands(*command_list), 0);
		}
	}
	else
	{
		(*current_cmd)->outfile = create_io_file(lexer->tokens[++(*i)], REDIRECT_APPEND);
		if (!(*current_cmd)->outfile)
		{
			fprintf(stderr, "Error: Failed to allocate memory for input redirection file\n");
			return (free_commands(*command_list), 0);
		}
	}
	return (1);
}

int	ft_parse_out_red(t_command **command_list, t_command **current_cmd, int *i, t_lexer *lexer)
{
	if (!*current_cmd)
	{
		*command_list = create_command();
		if (!*command_list)
		{
			fprintf(stderr, "Error: Failed to allocate memory for command\n");
			return (0);
		}
		*current_cmd = *command_list;
	}
	if (*i + 1 < lexer->token_count)
	{
		if (!ft_parse_out_red_two(command_list, current_cmd, i, lexer))
			return (0);
	}
	else
	{
		fprintf(stderr, "Syntax error: Missing output file\n");
		return (free_commands(*command_list), 0);
	}
	return (1);
}

int	ft_parse_cmd_arg(t_command **command_list, t_command **current_cmd, char *token)
{
	if (!*current_cmd)
	{
		*command_list = create_command();
		if (!*command_list)
		{
			fprintf(stderr, "Error: Failed to allocate memory for command\n");
			return (0);
		}
		*current_cmd = *command_list;
	}
	if (!(*current_cmd)->cmd)
	{
		(*current_cmd)->cmd = ft_strdup(token);
		if (!(*current_cmd)->cmd)
			return (free_commands(*command_list), 0);
		add_argument(*current_cmd, token);
	} 
	else
		add_argument(*current_cmd, token);
	return (1);
}

int	parse_tokens_statement(t_command **command_list, t_command **current_cmd, int *i, t_lexer *lexer)
{
	char 		*token;

	token = lexer->tokens[*i];
	if (ft_strcmp(token, "|") == 0)
	{
		if (!ft_parse_pipe(command_list, current_cmd))
			return (0);
	}
	else if (ft_strcmp(token, "<") == 0 || ft_strcmp(token, "<<") == 0)
	{
		if (!ft_parse_in_red(command_list, current_cmd, i, lexer))
			return (0);
	}
	else if (ft_strcmp(token, ">") == 0 || ft_strcmp(token, ">>") == 0)
	{
		if (!ft_parse_out_red(command_list, current_cmd, i, lexer))
			return (0);
	}
	else
	{
		if (!ft_parse_cmd_arg(command_list, current_cmd, token))
			return (0);
	}
	return (1);
}

t_command	*parse_tokens(t_lexer *lexer)
{
	t_command	*command_list;
	t_command	*current_cmd;
	int			i;

	command_list = NULL;
	current_cmd = NULL;
	i = -1;
	while (++i < lexer->token_count)
	{
		if (!parse_tokens_statement(&command_list, &current_cmd, &i, lexer))
			return (NULL);
	}
	return command_list;
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
