/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:34:38 by talin             #+#    #+#             */
/*   Updated: 2025/01/15 16:14:19 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <signal.h>
# include <errno.h>
# include <fcntl.h>
# include <dirent.h>
# include <term.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

typedef struct s_lexer
{
	char	**tokens;
	int		token_count;
}	t_lexer;

typedef struct s_io_file
{
	char	*file_name;
	int		redirect_type;
}	t_io_file;

typedef struct s_command
{
	char				*cmd;
	char				**args;
	t_io_file			*infile;
	t_io_file			*outfile;
	struct s_command	*next;
}	t_command;

int		ft_isspace(const char str);
size_t	ft_strnlen(const char *s, size_t max_len);
char	*ft_strndup(const char *s, size_t n);
void	add_token(t_lexer *lexer, char *token);
t_lexer	*tokenize(char *input);
void	free_lexer(t_lexer *lexer);
size_t	ft_strcspn(const char *str, const char *reject);
int		ft_tokenize_four(t_lexer *lexer, char *input);
void	ft_tokenize_three(t_lexer *lexer, char *input, int *i);
int		ft_tokenize_two(t_lexer *lexer, char *input, int *i);
int		ft_tokenize_one(t_lexer *lexer, char *input, int *i);
void	free_commands(t_command *cmd);
void	print_commands(t_command *cmd);
#endif