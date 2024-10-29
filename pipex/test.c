/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:22:45 by talin             #+#    #+#             */
/*   Updated: 2024/10/29 15:41:54 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void    callexecve()
{
 char *const args[] = { "ls", "-l", NULL };
 char *const envp[] = { NULL };
 
 execve("/usr/bin/ls", args, envp);
 perror("execve");
    exit(EXIT_FAILURE); // Make sure to exit the child process if execve fails 
}

int main(void)
{
	 pid_t pid;
	 int	pd[2];
	 
	 if (pipe(pd) == -1)
	 	return (1);
	 printf("Hi I am the main process. My PID is :%d\n", getpid());
	 pid = fork();
	 if (pid == -1)
	  printf("Error while forking\n");
	 else if (pid == 0)
	 {
		close(pd[0]);
		dup2(pd[1], 1);
		printf("I am the child. But now a new parent. My PID is :%d --- My child's PID is %d\n", getpid(), pid);
		callexecve();
	 }
	 else if (pid > 1)
	 {
		printf("I am the parent. My PID is :%d --- My child's PID is %d\n", getpid(), pid);
		waitpid(pid, NULL, 0); 
		printf("Got back the control?\n");
		close(pd[1]);
		dup2(pd[0], 0);
	 }
 }