/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:51:31 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/29 17:51:32 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H

char	**free_and_exit(char **res);
int		get_words_count(char const *s, char c);
void	set_start_end_pos(char **start, char **end, char c);
int		copy_str(char *start, char *end, char **dp);
char	**ft_split(char const *s, char c);

#endif
