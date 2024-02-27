/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:20:49 by andefern          #+#    #+#             */
/*   Updated: 2024/02/27 10:45:27 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//function for moving the player above
void	move_north(int x, int y, t_parameters *parameters)
{
	parameters->mlx.p_facing = 0;
	if (parameters->map[y - 1][x] != '1')
	{
		if (parameters->map[y - 1][x] == 'C')
		{
			parameters->c--;
			parameters->map[y - 1][x] = 'P';
			if (parameters->map[y][x] == 'M')
				parameters->map[y][x] = 'E';
			else
				parameters->map[y][x] = '0';
		}
		if (parameters->map[y - 1][x] == 'E')
		{
			if (parameters->c == 0)
				win_diesel(parameters);
			parameters->map[y - 1][x] = 'M';
			parameters->map[y][x] = '0';
		}
		move_north_2(x, y, parameters);
	}
}

//second part of the previous function
void	move_north_2(int x, int y, t_parameters *parameters)
{
	parameters->mlx.p_facing = 0;
	if (parameters->map[y - 1][x] != '1')
	{
		if (parameters->map[y - 1][x] == '0')
		{
			parameters->map[y - 1][x] = 'P';
			if (parameters->map[y][x] == 'M')
				parameters->map[y][x] = 'E';
			else
				parameters->map[y][x] = '0';
		}
		ft_printf("Movements: %d\n", ++parameters->orange_movement);
	}
}

//function for moving the player down
void	move_south(int x, int y, t_parameters *parameters)
{
	parameters->mlx.p_facing = 1;
	if (parameters->map[y + 1][x] != '1')
	{
		if (parameters->map[y + 1][x] == 'C')
		{
			parameters->c--;
			parameters->map[y + 1][x] = 'P';
			if (parameters->map[y][x] == 'M')
				parameters->map[y][x] = 'E';
			else
				parameters->map[y][x] = '0';
		}
		if (parameters->map[y + 1][x] == 'E')
		{
			if (parameters->c == 0)
				win_diesel(parameters);
			parameters->map[y + 1][x] = 'M';
			parameters->map[y][x] = '0';
		}
		move_south_2(x, y, parameters);
	}
}

//second part of the previous function
void	move_south_2(int x, int y, t_parameters *parameters)
{
	parameters->mlx.p_facing = 1;
	if (parameters->map[y + 1][x] != '1')
	{
		if (parameters->map[y + 1][x] == '0')
		{
			parameters->map[y + 1][x] = 'P';
			if (parameters->map[y][x] == 'M')
				parameters->map[y][x] = 'E';
			else
				parameters->map[y][x] = '0';
		}
		ft_printf("Movements: %d\n", ++parameters->orange_movement);
	}
}

//function that assigns keys to the desired movement
int	key_tracker(int keypressed, t_parameters *parameters)
{
	int	x;
	int	y;

	x = x_for_p(parameters);
	y = y_for_p(parameters);
	if (keypressed == 53)
		exit(0);
	if (keypressed == 13)
		move_north(x, y, parameters);
	if (keypressed == 1)
		move_south(x, y, parameters);
	if (keypressed == 2)
		move_east(x, y, parameters);
	if (keypressed == 0)
		move_west(x, y, parameters);
	window_draw(parameters);
	if (parameters->c == 0)
		unlocked_exit(parameters);
	windows_movements(parameters);
	return (keypressed);
}
