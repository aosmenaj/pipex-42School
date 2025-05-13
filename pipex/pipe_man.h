/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_man.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:51:06 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/02/29 17:51:07 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_MAN_H
# define PIPE_MAN_H

void	child_proc(const char *const *argv, char **env, int *conn, int *files);
void	open_files(char const *const *argv, int *files);
void	parent_proc(char const *const *argv, char **env, int *conn, int *files);
void	try_fork(char const *const *argv, char **env);

#endif
