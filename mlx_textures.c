/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:50:02 by andefern          #+#    #+#             */
/*   Updated: 2024/02/27 10:19:34 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//function that does free
void	free_splited(char **splited)
{
	int	i;

	i = -1;
	while (splited[++i])
		free(splited[i]);
	free(splited);
}

//function that exits if the sprites are broken
void	sprite_missing(t_parameters *parameters)
{
	if (parameters->mlx.wall == NULL || parameters->mlx.ground == NULL
		|| parameters->mlx.ground == NULL || parameters->mlx.p_north == NULL
		|| parameters->mlx.p_south == NULL || parameters->mlx.p_east == NULL
		|| parameters->mlx.p_west == NULL || parameters->mlx.c == NULL
		|| parameters->mlx.e == NULL || parameters->mlx.m == NULL)
	{
		ft_putstr_fd("Sprite Exploded\n", 2);
		leak_eraser(parameters);
	}
}

//function for adding textures
void	mlx_add_textures_player(t_parameters *parameters)
{
	int	a;
	int	b;

	parameters->mlx.p_north = mlx_xpm_file_to_image(\
	parameters->mlx.pointer, "textures/pixel_harvester_north.xpm", &a, &b);
	parameters->mlx.p_south = mlx_xpm_file_to_image(\
	parameters->mlx.pointer, "textures/pixel_harvester_south.xpm", &a, &b);
	parameters->mlx.p_east = mlx_xpm_file_to_image(\
	parameters->mlx.pointer, "textures/pixel_harvester_east.xpm", &a, &b);
	parameters->mlx.p_west = mlx_xpm_file_to_image(\
	parameters->mlx.pointer, "textures/pixel_harvester_west.xpm", &a, &b);
}

//function for adding textures
void	mlx_add_textures(t_parameters *parameters)
{
	int	a;
	int	b;

	parameters->mlx.wall = mlx_xpm_file_to_image(\
	parameters->mlx.pointer, "textures/wall.xpm", &a, &b);
	parameters->mlx.ground = mlx_xpm_file_to_image(\
	parameters->mlx.pointer, "textures/ground.xpm", &a, &b);
	parameters->mlx.c = mlx_xpm_file_to_image(\
	parameters->mlx.pointer, "textures/coin.xpm", &a, &b);
	parameters->mlx.e = mlx_xpm_file_to_image(\
	parameters->mlx.pointer, "textures/exit.xpm", &a, &b);
	parameters->mlx.m = mlx_xpm_file_to_image(\
	parameters->mlx.pointer, "textures/m.xpm", &a, &b);
	mlx_add_textures_player(parameters);
	sprite_missing(parameters);
}

//function that shows the player movements on the screen
void	windows_movements(t_parameters *parameters)
{
	char	*orange_movement;
	char	*c;

	orange_movement = ft_itoa(parameters->orange_movement);
	c = ft_itoa(parameters->c);
	mlx_string_put(parameters->mlx.pointer, parameters->mlx.window,
		10, 10, -1, "Movements: ");
	mlx_string_put(parameters->mlx.pointer, parameters->mlx.window,
		120, 10, -1, orange_movement);
	mlx_string_put(parameters->mlx.pointer, parameters->mlx.window,
		300, 10, -1, "Colectables: ");
	mlx_string_put(parameters->mlx.pointer, parameters->mlx.window,
		400, 10, -1, c);
	free(orange_movement);
	free(c);
}
