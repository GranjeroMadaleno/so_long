/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:23:03 by andefern          #+#    #+#             */
/*   Updated: 2024/02/27 10:51:54 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//function that selects the correct image
void	p_image_selector(t_parameters *parameters, int x, int y)
{
	if (parameters->mlx.p_facing == 0)
	{
		mlx_put_image_to_window(parameters->mlx.pointer, \
		parameters->mlx.window, \
		parameters->mlx.p_north, x * 64, y * 64);
	}
	if (parameters->mlx.p_facing == 1)
	{
		mlx_put_image_to_window(parameters->mlx.pointer, \
		parameters->mlx.window, \
		parameters->mlx.p_south, x * 64, y * 64);
	}
	if (parameters->mlx.p_facing == 2)
	{
		mlx_put_image_to_window(parameters->mlx.pointer, \
		parameters->mlx.window, \
		parameters->mlx.p_east, x * 64, y * 64);
	}
	if (parameters->mlx.p_facing == 3)
	{
		mlx_put_image_to_window(parameters->mlx.pointer, \
		parameters->mlx.window, \
		parameters->mlx.p_west, x * 64, y * 64);
	}
}

//function that selects the image for each element
void	image_selector(t_parameters *parameters, int x, int y)
{
	if (parameters->map[y][x] == '1')
		mlx_put_image_to_window(parameters->mlx.pointer, \
		parameters->mlx.window, \
		parameters->mlx.wall, x * 64, y * 64);
	if (parameters->map[y][x] == 'C')
	{
		mlx_put_image_to_window(parameters->mlx.pointer, \
		parameters->mlx.window, \
		parameters->mlx.c, x * 64, y * 64);
	}
}

//function that selects the image for each element
void	image_selector_2(t_parameters *parameters, int x, int y)
{
	if (parameters->map[y][x] == 'P')
		p_image_selector(parameters, x, y);
	if (parameters->map[y][x] == 'E')
	{
		mlx_put_image_to_window(parameters->mlx.pointer, \
		parameters->mlx.window, \
		parameters->mlx.e, x * 64, y * 64);
	}
	if (parameters->map[y][x] == 'M')
	{
		mlx_put_image_to_window(parameters->mlx.pointer, \
		parameters->mlx.window, \
		parameters->mlx.m, x * 64, y * 64);
	}
}

//function that erases memory
int	leak_eraser(t_parameters *parameters)
{
	if (parameters->mlx.wall)
		mlx_destroy_image(parameters->mlx.pointer, parameters->mlx.wall);
	if (parameters->mlx.ground)
		mlx_destroy_image(parameters->mlx.pointer, parameters->mlx.ground);
	if (parameters->mlx.c)
		mlx_destroy_image(parameters->mlx.pointer, parameters->mlx.c);
	if (parameters->mlx.e)
		mlx_destroy_image(parameters->mlx.pointer, parameters->mlx.e);
	if (parameters->mlx.m)
		mlx_destroy_image(parameters->mlx.pointer, parameters->mlx.m);
	if (parameters->mlx.p_north)
		mlx_destroy_image(parameters->mlx.pointer, parameters->mlx.p_north);
	if (parameters->mlx.p_south)
		mlx_destroy_image(parameters->mlx.pointer, parameters->mlx.p_south);
	if (parameters->mlx.p_east)
		mlx_destroy_image(parameters->mlx.pointer, parameters->mlx.p_east);
	if (parameters->mlx.p_west)
		mlx_destroy_image(parameters->mlx.pointer, parameters->mlx.p_west);
	if (parameters->mlx.window)
		mlx_destroy_window(parameters->mlx.pointer, parameters->mlx.window);
	free(parameters->map_str);
	free_splited(parameters->map);
	free_splited(parameters->map_phill);
	exit(0);
}

//function for writing in the terminal that you won
void	win_diesel(t_parameters *parameters)
{
	ft_printf("Harvesting completed, congrats!!\n", 1);
	leak_eraser(parameters);
}
