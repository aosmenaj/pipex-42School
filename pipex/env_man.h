/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_man.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:49:31 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/29 17:49:32 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_MAN_H
# define ENV_MAN_H

# include <stddef.h>

char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*get_exec(char const *cmd, char **env);
char	*find_path(char **env);

#endif // ENV_MAN_H
