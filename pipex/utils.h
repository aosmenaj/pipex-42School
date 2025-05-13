/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:51:40 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/29 17:51:41 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	display_error_and_die(char const *s);
void	display_str(char const *s);
int		mystrlen(char const *s);
void	free_args(char **argv);

#endif
