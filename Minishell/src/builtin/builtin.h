/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:53:35 by okandemi          #+#    #+#             */
/*   Updated: 2023/07/19 16:53:36 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../../include/minishell.h"

int		built_in_ctl(char *str);
char	*new_str(char *str, char *new);
char	*get_env(char *key);
void	free_double_pointer(char ***str);
void	ft_echo(char **arg);
void	n_ctl(char **arg, int i);
int		ft_cd(char *dest, char *old_dir);
void	set_tmp(char **tmp, int *i);
void	set_pwds(char *old_dir, int find);
void	update_env_pwds(char *old_dir);
void	update_env(char *keyval, int state);
void	add_env_success(char *keyval, char ***tmp, int *i);
void	set_keys(char *keyval, int *find, int *i);
int		do_export(char **str);
void	print_export(char *str);
void	set_key_and_value(char **key, char **value, int *i);
void	print_env(char **str);
int		ft_unset(char **str);
void	ft_echo(char **arg);
int		getting_number_in_exit(char *str);
int		ft_chrcmp(char c1, char c2);
void	add_env(char *keyval, char **tmp, int find);
int		repeat_index(char *env_name, char *cmd);
int		size_env(char **env);
int		is_invalid_arg(char **str);
int		size_expand_len(char *cmd);
int		is_env(char *str);
void	exit_func(char **cmnd);
char	*env_name(int i);
#endif