/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:50:57 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/29 17:50:58 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"
#include <stdlib.h>

char	**free_and_exit(char **res)
{
	while (res && *res)
	{
		free(*res);
		++res;
	}
	if (res)
		free(res);
	return (NULL);
}

int	get_words_count(char const *s, char c)
{
	int	count;
	int	flag;
	int	i;

	count = 0;
	i = 0;
	flag = 1;
	while (s[i])
	{
		if (c == s[i])
		{
			flag = 1;
		}
		else if (flag)
		{
			flag = 0;
			++count;
		}
		i++;
	}
	return (count);
}

void	set_start_end_pos(char **start, char **end, char c)
{
	while (*start && **start == c)
		++*start;
	*end = *start;
	while (*end && **end != c && **end)
		++*end;
}

int	copy_str(char *start, char *end, char **dp)
{
	char	*p;

	*dp = (char *)malloc(sizeof(char) * (size_t)(end - start + 1));
	if (!dp)
		return (0);
	p = *dp;
	while (start != end)
	{
		*p++ = *start++;
	}
	*p = '\0';
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		howmany;
	char	**res;
	char	**dp;
	char	*start;
	char	*end;

	howmany = get_words_count(s, c);
	res = (char **)malloc(sizeof(char *) * (size_t)(howmany + 1));
	if (!res)
		return (NULL);
	dp = res;
	start = (char *)s;
	end = start;
	while (howmany)
	{
		set_start_end_pos(&start, &end, c);
		if (start != end)
			if (!copy_str(start, end, dp))
				return (free_and_exit(res));
		start = end + 1;
		dp++;
		howmany--;
	}
	*dp = NULL;
	return (res);
}
