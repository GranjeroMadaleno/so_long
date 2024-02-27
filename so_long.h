/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:59:10 by andefern          #+#    #+#             */
/*   Updated: 2024/02/27 11:22:09 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include "mlx/mlx.h"

typedef struct s_mlx_parameters
{
	int		p_facing;
	void	*p_north;
	void	*p_south;
	void	*p_east;
	void	*p_west;
	void	*c;
	void	*e;
	void	*m;
	void	*ground;
	void	*wall;
	void	*window;
	void	*pointer;
}			t_mlx_parameters;

typedef struct s_parameters
{
	int					p;
	int					c;
	int					e;
	int					map_nitude;
	int					rows;
	int					cols;
	int					map_size;
	int					orange_movement;
	char				*map_str;
	char				**map;
	char				**map_phill;
	t_mlx_parameters	mlx;
}						t_parameters;

//ERRORS & EXITS
void	error_matic(char *error);
void	free_splited(char **splited);
void	win_diesel(t_parameters *parameters);
int		leak_eraser(t_parameters *parameters);
int		red_cross_chili_peppers(t_parameters *parameters);
//VERIFICATIONS & CHECKS
void	is_ber_file(const char *file_name);
void	check_walls(t_parameters *parameters);
void	check_chars(t_parameters *parameters);
void	gar_phill(t_parameters *parameters);
void	checkster_cheetos(t_parameters *parameters);
void	sprite_missing(t_parameters *parameters);
//READ MAP
void	get_map_str(t_parameters *parameters, const char *map_path);
//COUNTS
void	count_characters(t_parameters *parameters);
void	count_rows_and_cols(t_parameters *parameters);
//P POSITION LOCATORS
int		y_for_p(t_parameters *parameters);
int		x_for_p(t_parameters *parameters);
//INITS
void	initializer(t_parameters *parameters, const char *map_path);
int		ber_size(const char *map_path);
int		key_tracker(int keytracker, t_parameters *parameters);
//FLUD_PHILL
void	flud_phill(t_parameters *parameters, int y, int x);
//MLX
void	mlx_add_textures(t_parameters *parameters);
void	mlx_add_textures_player(t_parameters *parameters);
void	mlx_starter_pack(t_parameters *parameters);
void	mlx_initializer(t_parameters *parameters);
void	image_selector(t_parameters *parameters, int x, int y);
void	image_selector_2(t_parameters *parameters, int x, int y);
void	p_image_selector(t_parameters *parameters, int x, int y);
void	window_draw(t_parameters *parameters);
void	unlocked_exit(t_parameters *parameters);
void	windows_movements(t_parameters *parameters);
//MOVEMENTS
void	move_north(int x, int y, t_parameters *parameters);
void	move_north_2(int x, int y, t_parameters *parameters);
void	move_south(int x, int y, t_parameters *parameters);
void	move_south_2(int x, int y, t_parameters *parameters);
void	move_east(int x, int y, t_parameters *parameters);
void	move_east_2(int x, int y, t_parameters *parameters);
void	move_west(int x, int y, t_parameters *parameters);
void	move_west_2(int x, int y, t_parameters *parameters);

#endif
