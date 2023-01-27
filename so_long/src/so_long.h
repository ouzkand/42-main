/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:43:35 by okandemi          #+#    #+#             */
/*   Updated: 2023/01/27 12:55:21 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

# define PL_FR "./src/images/player_front.xpm"
# define PL_LEFT "./src/images/player_left.xpm"
# define PL_RIGHT "./src/images/player_right.xpm"
# define PL_BACK "./src/images/player_back.xpm"
# define EXIT "./src/images/exit.xpm"
# define COLLECTIBLE "./src/images/collectible.xpm"
# define WALL "./src/images/wall.xpm"
# define GROUND "./src/images/ground.xpm"

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*grnd;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player_fr;
	void	*player_r;
	void	*player_l;
	void	*player_b;
	char	curr_pos;
	char	**map;
	char	**tmp_map;
	char	*move_scrn;
	int		imgx;
	int		imgy;
	int		map_is_true;
	int		map_x;
	int		map_y;
	int		gold_nbr;
	int		tmp_number;
	int		move_count;
	int		player_x;
	int		player_y;
}	t_data;

int		key_event(int keycode, t_data *data);
void	move(t_data *data, int x, int y, char c);
void	x_y_operation(int *x, int *y, t_data *data);
int		is_valid_movement(t_data *data, int x, int y);
void	render_after_move(t_data *data);
void	*ft_calloc(size_t num, size_t size);
void	ft_bzero(void *s, size_t n);
void	score(t_data *data);
int		close_window(t_data *data);
void	error(char *str, t_data *data);
void	free_all(t_data *data);
void	free_all_2(t_data *data);
void	*ft_memset(void *b, int c, size_t len);
void	init_image(t_data *data);
void	put_image(t_data *data);
void	put_image_player(t_data *data, int x, int y);
void	check_ber_extension(char *str, t_data *data);
void	make_map(t_data *data, char *file);
void	check_map_wall(t_data *data);
void	check_components(t_data *data);
void	check_atleast(t_data *data, int *p, int *e, int *c);
void	copy_maze(t_data *data);
void	check_is_valid_map(t_data *data, int x, int y);
void	check_can_all_collectible(t_data *data);
char	*ft_strdup(const char *str);
size_t	my_strlen(const char *str);
char	*ft_itoa(int n);
void	check_image(t_data *data);

#endif