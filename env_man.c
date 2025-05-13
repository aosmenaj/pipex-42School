/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:49:27 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/29 17:50:16 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_man.h"
#include "ft_split.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = (int)ft_strlen(s1);
	s2_len = (int)ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size_t)(s1_len + s2_len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i - (s1_len)])
	{
		str[i] = s2[i - (s1_len)];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p++)
	{
	}
	return ((size_t)(p - s - 1));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*p1;
	unsigned const char	*p2;

	if (n == 0)
		return (0);
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n--)
	{
		if (!*p1 || *p1 != *p2)
			return (*p1 - *p2);
		++p1;
		++p2;
	}
	return (0);
}

char	*get_exec(const char *cmd, char **env)
{
	char	*path;
	char	*temp;
	char	**execs;
	int		i;

	i = 0;
	path = find_path(env);
	execs = ft_split(path, ':');
	while (execs[i])
	{
		if (i != 0)
			free(path);
		temp = ft_strjoin(execs[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (!access(path, F_OK))
		{
			free_args(execs);
			return (path);
		}
		i++;
	}
	free_args(execs);
	free(path);
	return (NULL);
}

char	*find_path(char **env)
{
	while (env && *env)
	{
		if (!ft_strncmp("PATH=", *env, 5))
			return (*env + 5);
		++env;
	}
	return (NULL);
}
