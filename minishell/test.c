/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:46:19 by talin             #+#    #+#             */
/*   Updated: 2025/01/22 15:27:26 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char	**print_env_from_proc() {
	char	**env;
	int		count;
    int fd = open("/proc/self/environ", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return (NULL);
    }
    size_t buffer_size = 10;
    char *buffer = malloc(buffer_size);
    if (!buffer) {
        perror("malloc");
        close(fd);
        return (NULL);
    }
    ssize_t bytes_read = 0;
    size_t total_read = 0;
	count = 0;
    while ((bytes_read = read(fd, buffer + total_read, buffer_size - total_read)) > 0) {
        total_read += bytes_read;
        if (total_read == buffer_size) {
            size_t new_size = buffer_size * 2;
            char *new_buffer = malloc(new_size);
            if (!new_buffer) {
                perror("malloc");
                free(buffer);
                close(fd);
                return (NULL);
            }
            memcpy(new_buffer, buffer, buffer_size);
            free(buffer);
            buffer = new_buffer;
            buffer_size = new_size;
        }
    }
    close(fd);
    if (bytes_read == -1) {
        perror("read");
        free(buffer);
        return (NULL);
    }
    buffer[total_read] = '\0';
    char *var = buffer;
    while (var < buffer + total_read) {
        var += strlen(var) + 1;
		count++;
    }
	env = (char **)malloc(sizeof(char *) * (count + 1));
	if (!env)
	{
		free(buffer);
		return (NULL);
	}
	var = buffer;
	count = 0;
	while (var < buffer + total_read)
	{
		env[count++] = strdup(var); 
		var += strlen(var)+1;
	}
	env[count] = NULL;
    free(buffer);
	return (env);
}

int main() {
    char **env = print_env_from_proc();
	int i = -1;
	while (env[++i])
	{
		printf("%s\n", env[i]);
		free(env[i]);
	}
	free(env);
    return 0;
}
