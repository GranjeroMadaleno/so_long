/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:10:07 by andefern          #+#    #+#             */
/*   Updated: 2024/02/27 13:21:30 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//function that changes the door's sprite when this opens
void	unlocked_exit(t_parameters *parameters)
{
	int	a;
	int	b;

	mlx_destroy_image(parameters->mlx.pointer, parameters->mlx.e);
	parameters->mlx.e = mlx_xpm_file_to_image(\
	parameters->mlx.pointer, "textures/unlocked.xpm", &a, &b);
}

//function that assigns images to walls
void	window_draw(t_parameters *parameters)
{
	int	x;
	int	y;

	y = 0;
	while (parameters->map[y])
	{
		x = 0;
		while (parameters->map[y][x])
		{
			mlx_put_image_to_window(parameters->mlx.pointer, \
			parameters->mlx.window, \
			parameters->mlx.ground, x * 64, y * 64);
			image_selector(parameters, x, y);
			image_selector_2(parameters, x, y);
			x++;
		}
		y++;
	}
}

//function that initializes the functions related to the mlx
void	mlx_initializer(t_parameters *parameters)
{
	parameters->mlx.p_facing = 2;
	parameters->mlx.p_north = NULL;
	parameters->mlx.p_south = NULL;
	parameters->mlx.p_east = NULL;
	parameters->mlx.p_west = NULL;
	parameters->mlx.ground = NULL;
	parameters->mlx.wall = NULL;
	parameters->mlx.window = NULL;
	parameters->mlx.pointer = NULL;
	parameters->mlx.m = NULL;
	parameters->mlx.e = NULL;
	parameters->mlx.c = NULL;
}

//function that makes the program close correctly using the cross
int	red_cross_chili_peppers(t_parameters *parameters)
{
	ft_printf("You COWARDLY pressed the red cross\n", 1);
	leak_eraser(parameters);
	return (0);
}

//function that initializes the game screen
void	mlx_starter_pack(t_parameters *parameters)
{
	mlx_initializer(parameters);
	parameters->mlx.pointer = mlx_init();
	parameters->mlx.window = mlx_new_window(parameters->mlx.pointer, \
	parameters->cols * 64, parameters->rows * 64, "so_long");
	mlx_add_textures(parameters);
	window_draw(parameters);
	mlx_key_hook(parameters->mlx.window, key_tracker, parameters);
	mlx_hook(parameters->mlx.window, 17, 0, \
	red_cross_chili_peppers, parameters);
	mlx_loop(parameters->mlx.pointer);
}
