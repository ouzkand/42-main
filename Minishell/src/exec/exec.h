/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:54:27 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:54:29 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../../include/minishell.h"

int		is_executor(char **expand_cmd);
int		get_size_t_cmd(t_cmnd *t_cmd);
int		is_directory(char *expand_cmnd);
int		input(t_cmnd *t_cmd);
int		input_output(t_cmnd *t_cmd);
int		output(t_cmnd *t_cmd);
void	file_add(char **file, char **paths, t_cmnd *t_cmd);
void	heredoc(t_cmnd *t_cmd);
void	dup2_scale(t_cmnd *t_cmd, t_pip *pipe);
void	close_all(t_pip *pipe);
void	close_unnecessary_fd(t_pip *pipe);
void	wait_pid_all(t_cmnd *t_cmd);
void	get_paths(void);
t_cmnd	*get_cmnd(t_cmnd *t_cmd, int context);
t_cmnd	*get_cmnd_next(t_cmnd *t_cmd, int context);
t_pip	*init_pipe(void);

#endif