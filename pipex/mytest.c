#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_check_set_unset(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=/", 6) == 0)
		{
			printf("good set\n");
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	int num = ft_check_set_unset(env);
	printf("num: %d\n", num);
}
