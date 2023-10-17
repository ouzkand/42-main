/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:17:57 by ydegerli          #+#    #+#             */
/*   Updated: 2023/10/07 14:54:06 by okandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlxlib/mlx.h"
# include "gnl/get_next_line.h"
# include "gnl/get_next_line_bonus.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

# define WIDTH 800
# define HEIGHT 600
# define TEXTWIDHT 64
# define TEXTHEIGHT 64
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define L_AR 123
# define R_AR 124
# define PAUSE 35

typedef struct s_image
{
	void	*images;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	int		w;
	int		h;
}		t_image;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_map_info
{
	char	*north;
	char	*east;
	char	*south;
	char	*west;
	char	*c;
	char	*f;
}			t_MapInfo;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_mouse
{
	int	old_pos_x;
	int	old_pos_y;
	int	pos_x;
	int	pos_y;
}				t_mouse;

typedef struct s_move
{
	double	rot_speed;
	double	speed;
	int		forward;
	int		left;
	int		right;
	int		backward;
	int		rot_left;
	int		rot_right;
}		t_move;

typedef struct s_math
{
	double		camera_x;
	double		camera_y;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			pitch;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			texnum;
	double		wall_x;
	double		tex_x;
	double		step;
	double		texpos;
}		t_math;

typedef struct s_cub3d
{
	t_MapInfo	*map_info;
	t_move		*move;
	t_player	*player;
	t_mouse		*mouse;
	t_image		image;
	t_image		north;
	t_image		south;
	t_image		east;
	t_image		west;
	t_color		floor;
	t_color		sky;
	t_math		math;
	void		*window;
	void		*mlx;
	char		**map;
	int			**int_map;
	int			length_x;
	int			length_y;
	int			fd;
	int			lock;
	int			max_line;
	int			line_count;
	char		**tmp_map;
	int			map_hei;
	int			data_len;
	char		*file;
	char		*tmp_file;
	int			tmp_fd;
}				t_cub3d;

unsigned int	get_pixel_in_tex(t_image tex, int x, int y);
void			split_screen_two(t_cub3d *cub3d, t_math *math);
void			calculating_rays(t_cub3d *cub3d, t_math *math);
void			does_ray_hitting_wall(t_cub3d *cub3d, t_math *math);
void			calculating_drawing_screen_and_fisheye_ctl(t_cub3d *cub3d, \
t_math *math);
void			drawing_screen(t_cub3d *cub3d, t_math *math);
void			painting(t_cub3d *cub3d, int ct, int ctt, unsigned int color);
void			frame_calc(t_cub3d *cub3d);;
void			move(t_cub3d *cub3d);
int				create_trgb(int t, int r, int g, int b);
void			rot_left(t_cub3d *cub3d);
void			move_right(t_cub3d *cub3d);
void			move_left(t_cub3d *cub3d);
void			move_back(t_cub3d *cub3d);
void			get_color(t_cub3d *cub3d);
void			color_ctl(t_cub3d *cub3d);
void			move_forward(t_cub3d *cub3d);
void			rot_right(t_cub3d *cub3d);
void			rotate_with_mouse(t_cub3d *cub3d);
void			draw_image(t_cub3d *cub3d);
void			draw_pause(t_cub3d *cub3d, int color);
void			draw_maze(t_cub3d *cub3d);
void			put_mini_map_red_dot(t_cub3d *cub3d, int color);
void			find_longest_line(t_cub3d *cub3d);
void			find_line_count(t_cub3d *cub3d);
int				red_x_close(int keycode, t_cub3d *cub3d);
int				key_release(int keycode, t_cub3d *cub3d);
int				key_press(int keycode, t_cub3d *cub3d);
void			set_user(t_cub3d *cub3d, int i, int j);
void			set_player_dir(t_cub3d *cub3d, int i, int j);
int				is_user_zero(int c);
void			init2(t_cub3d *cub3d);
void			text_len(t_cub3d *cub3d);
void			texture_ctl(t_cub3d *cub3d);
void			free_int_map(t_cub3d *cub3d);
void			ft_char_ctrl(t_cub3d *cub3d);
void			free_map_info(t_cub3d *cub3d);
void			free_cub3d_map(t_cub3d *cub3d);
void			init(t_cub3d *cub3d, char *av);
void			error_data_ctl(t_cub3d *cub3d);
void			taking_pics(t_cub3d *cub3d);
void			extension_ctl(char *extension);
void			ft_newline_ctrl(t_cub3d *cub3d);
void			draw_pause(t_cub3d *cub3d, int color);
void			ft_player_position_ctrl(t_cub3d *cub3d);
int				key_press(int keycode, t_cub3d *cub3d);
void			err_data_ctl(char *str, t_cub3d *cub3d);
void			err_plyr_ctrl(char *str, t_cub3d *cub3d);
int				red_x_close(int keycode, t_cub3d *cub3d);
void			map_ctl(char *file_name, t_cub3d *cub3d);
int				check_player(t_cub3d *vals, int i, int j);
int				data_chck(char *file_name, t_cub3d *cub3d);
char			*data_ctl(char *file_name, t_cub3d *cub3d);
void			rebuild_map(char *file_name, t_cub3d *cub3d);
void			put_pxl_to_img(t_cub3d *cub3d, int x, int y, int color);
void			ft_player_pos(t_cub3d *cub3d, int i, int j, int player_count);
#endif
