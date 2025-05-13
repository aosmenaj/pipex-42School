/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:51:55 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/29 17:51:56 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	display_str(char const *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		write(2, &s[i++], 1);
	write(2, "\n", 1);
}

int	mystrlen(char const *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
			++i;
	return (i);
}

void	display_error_and_die(char const *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	free_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	i--;
	while (i >= 0)
	{
		free(argv[i]);
		i--;
	}
	free(argv);
	return ;
}
