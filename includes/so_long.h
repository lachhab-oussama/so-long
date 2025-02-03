/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:08:13 by olachhab          #+#    #+#             */
/*   Updated: 2025/02/02 15:59:37 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../includes/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BACKGROUND_COLOR 0x34a853
# define WIDTH_PIXEL 32
# define HEIGHT_PIXEL 32
# define PIXEL_REF 32

typedef struct s_big
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	int		img_width;
	int		img_height;
	char	*wall_path;
	void	*img_wall;
	char	*map_path;
	int		map_x;
	int		map_y;
	void	*img_player;
	char	*player_path;
	int		player_x;
	int		player_y;
	void	*img_exit;
	char	*exit_path;
	int		exit_x;
	int		exit_y;
	int		collectibles_number;
	int		player_number;
	int		exit_number;
	void	*img_collect;
	char	*collect_path;
	int		collect_x;
	int		collect_y;
	char	**map;
	int		map_width;
	int		map_height;
	char	*trace_img_player;
	void	*img_trace_player;
	int		prev_player_x;
	int		prev_player_y;
	int		count_moves;
	char	**tab;
	int		x;
	int		y;
}			t_big;

int			argumet_num(int ac);
void		check_extention_map(t_big *data);
int			close_window(void *param);

/*-----------load map---------------*/

void		load_map(t_big *data);
void		check_all_lines(t_big *data);

/*----------------------------------*/

void		init_data(t_big *data);
int			initialize_images(t_big *data);

/*-------------check map------------*/

void		flood_fill(t_big *data);
void		map_border_check(t_big *data);
void		get_player_position(t_big *data);
void		get_map_in_tab(t_big *data);

/*----------------------------------*/

void		chek_elements_of_map(t_big *data);
void		validation_of_map(t_big *data);
void		get_map_size(t_big *data);
int			key_hook(int keycode, t_big *data);
void		prepare_maps(t_big *data);
void		fil_to_win(t_big data, int x, int y);
void		wall_img(t_big *data);
void		player_img(t_big *data);
void		exit_img(t_big *data);
void		collect_img(t_big *data);
void		trace_img_player(t_big *data);

/*------------player moves-----------*/

void		player_move_up(t_big *data);
void		player_move_down(t_big *data);
void		player_move_left(t_big *data);
void		player_move_right(t_big *data);

/*----------------------------------*/

// void render_map(t_big *data);

void		find_exit(t_big *data);
void		find_collect(t_big *data);
void		find_player_position(t_big *data);
void		render_free_space(t_big data);
void		cleanup(t_big *data);

/*-------------Print Errors------------*/

void		print_error(char *str);

#endif
