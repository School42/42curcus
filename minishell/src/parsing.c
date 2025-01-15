/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:27:03 by talin             #+#    #+#             */
/*   Updated: 2025/01/15 22:01:24 by ubuntu           ###   ########.fr       */
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
	{
		while (cmd->args[arg_count])
			arg_count++;
	}
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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (0 - ((unsigned char)s2[i]));
	if (!s2)
		return ((unsigned char)s1[i]);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

t_command	*parse_tokens(t_lexer *lexer)
{
	char 		*token;
	t_command	*command_list;
	t_command	*current_cmd;
	int			i;

	command_list = NULL;
	current_cmd = NULL;
	i = -1;
	while (++i < lexer->token_count)
	{
		token = lexer->tokens[i];
		if (ft_strcmp(token, "|") == 0)
		{
			if (!current_cmd)
			{
				fprintf(stderr, "Syntax error: Pipe '|' without a preceding command\n");
				return (free_commands(command_list), NULL);
			}
			current_cmd->next = create_command();
			if (!current_cmd->next)
			{
				fprintf(stderr, "Error: Failed to allocate memory for command\n");
				return (free_commands(command_list), NULL);
			}
			current_cmd = current_cmd->next;
		}
		else if (ft_strcmp(token, "<") == 0 || ft_strcmp(token, "<<") == 0)
		{
			if (!current_cmd)
			{
				command_list = create_command();
				if (!command_list)
				{
					fprintf(stderr, "Error: Failed to allocate memory for command\n");
					return NULL;
				}
				current_cmd = command_list;
			}
			if (i + 1 < lexer->token_count)
			{
				if (ft_strcmp(token, "<") == 0)
				{
					current_cmd->infile = create_io_file(lexer->tokens[++i], REDIRECT_INPUT);
					if (!current_cmd->infile)
	                {
	                    fprintf(stderr, "Error: Failed to allocate memory for input redirection file\n");
	                    return (free_commands(command_list), NULL);
	                }
				}
				else
				{
					current_cmd->infile = create_io_file(lexer->tokens[++i], REDIRECT_HEREDOC);
					if (!current_cmd->infile)
					{
						fprintf(stderr, "Error: Failed to allocate memory for input redirection file\n");
						return (free_commands(command_list), NULL);
					}
				}
			}
			else
			{
				fprintf(stderr, "Syntax error: Missing input file after '%s'\n", token);
				return (free_commands(command_list), NULL);
			}
		}
		else if (ft_strcmp(token, ">") == 0 || ft_strcmp(token, ">>") == 0)
		{
			if (!current_cmd)
			{
				command_list = create_command();
				if (!command_list)
				{
					fprintf(stderr, "Error: Failed to allocate memory for command\n");
					return NULL;
				}
				current_cmd = command_list;
			}
			if (i + 1 < lexer->token_count)
			{
				if (ft_strcmp(token, ">") == 0)
				{
					current_cmd->outfile = create_io_file(lexer->tokens[++i], REDIRECT_OUTPUT);
					if (!current_cmd->outfile)
	                {
	                    fprintf(stderr, "Error: Failed to allocate memory for input redirection file\n");
	                    return (free_commands(command_list), NULL);
	                }
				}
				else
				{
					current_cmd->outfile = create_io_file(lexer->tokens[++i], REDIRECT_APPEND);
					if (!current_cmd->outfile)
					{
						fprintf(stderr, "Error: Failed to allocate memory for input redirection file\n");
						return (free_commands(command_list), NULL);
					}
				}
			}
			else
			{
				fprintf(stderr, "Syntax error: Missing output file after '%s'\n", token);
				return (free_commands(command_list), NULL);
			}
		}
		else
		{
			if (!current_cmd)
			{
				command_list = create_command();
				if (!command_list)
				{
					fprintf(stderr, "Error: Failed to allocate memory for command\n");
					return NULL;
				}
				current_cmd = command_list;
			}
			if (!current_cmd->cmd)
			{
				current_cmd->cmd = ft_strdup(token);
				if (!current_cmd->cmd)
					return (free_commands(command_list), NULL);
				add_argument(current_cmd, token);
			} 
			else
				add_argument(current_cmd, token);
		}
	}
	return command_list;
}

void	ft_free_io_file(t_io_file *file)
{
	free(file->file_name);
	free(file);
}

void	free_commands(t_command *cmd)
{
	t_command	*temp;
	int			i;

	while (cmd)
	{
		temp = cmd;
		if (temp->cmd)
			free(temp->cmd);
		if (temp->args)
		{
			i = -1;
			while (temp->args[++i])
				free(temp->args[i]);
			free(temp->args);
		}
		if (temp->infile)
			ft_free_io_file(temp->infile);
		if (temp->outfile)
			ft_free_io_file(temp->outfile);
		free(temp);
		cmd = cmd->next;
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
