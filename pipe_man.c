/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:51:15 by aosmenaj          #+#    #+#             */
/*   Updated: 2025/01/17 17:13:23 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_man.h"
#include "env_man.h"
#include "ft_split.h"
#include "utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

void	child_proc(char const *const *argv, char **env, int *conn, int *files)
{
	char	**cmd1;
	char	*exec;

	dup2(files[0], STDIN_FILENO);
	close(files[0]);
	dup2(conn[1], STDOUT_FILENO);
	close(conn[1]);
	cmd1 = ft_split(argv[2], ' ');
	exec = get_exec(cmd1[0], env);
	if (!exec)
	{
		free_args(cmd1);
		perror(argv[2]);
		exit(127);
	}
	if (-1 == execve(exec, cmd1, env))
	{
		free_args(cmd1);
		free(exec);
		display_error_and_die("execve() in child failed.");
	}
}

void	parent_proc(char const *const *argv, char **env, int *conn, int *files)
{
	char	**cmd2;
	char	*exec;

	wait(NULL);
	close(files[0]);
	close(conn[1]);
	dup2(conn[0], STDIN_FILENO);
	close(conn[0]);
	dup2(files[1], STDOUT_FILENO);
	close(files[1]);
	cmd2 = ft_split(argv[3], ' ');
	exec = get_exec(cmd2[0], env);
	if (!exec)
	{
		free_args(cmd2);
		perror(argv[3]);
		exit(127);
	}
	if (-1 == execve(exec, cmd2, env))
	{
		free_args(cmd2);
		free(exec);
		display_error_and_die("execve() in child failed.");
	}
}

void	open_files(char const *const *argv, int *files)
{
	files[0] = open(argv[1], O_RDONLY, 0777);
	files[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (-1 == files[0] || (-1 == files[1]))
	{
		if (-1 == files[0] && !access(argv[1], F_OK))
		{
			perror(argv[1]);
			exit(EXIT_SUCCESS);
		}
		if (-1 == files[0])
			perror(argv[1]);
		else if ((-1 == files[1]))
			perror(argv[4]);
		exit(EXIT_FAILURE);
	}
}

void	try_fork(char const *const *argv, char **env)
{
	int		conn[2];
	int		files[2];
	pid_t	cpid;

	open_files(argv, files);
	if (-1 == pipe(conn))
		display_error_and_die("pipe() failed.");
	cpid = fork();
	if (-1 == cpid)
		display_error_and_die("fork() failed.");
	if (0 == cpid)
		child_proc(argv, env, conn, files);
	else
		parent_proc(argv, env, conn, files);
}
