/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:51:49 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/29 17:51:50 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_man.h"
#include "utils.h"
#include <unistd.h>

int	main(int argc, char *argv[], char *env[])
{
	if (5 != argc)
	{
		display_str("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (0);
	}
	try_fork((char const *const *)argv, env);
	return (1);
}
