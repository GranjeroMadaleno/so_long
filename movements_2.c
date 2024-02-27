/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:52:30 by andefern          #+#    #+#             */
/*   Updated: 2024/02/26 12:17:09 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//function for moving the player to the right
void	move_east(int x, int y, t_parameters *parameters)
{
	parameters->mlx.p_facing = 2;
	if (parameters->map[y][x + 1] != '1')
	{
		if (parameters->map[y][x + 1] == 'C')
		{
			parameters->c--;
			parameters->map[y][x + 1] = 'P';
			if (parameters->map[y][x] == 'M')
				parameters->map[y][x] = 'E';
			else
				parameters->map[y][x] = '0';
		}
		if (parameters->map[y][x + 1] == 'E')
		{
			if (parameters->c == 0)
				win_diesel(parameters);
			parameters->map[y][x + 1] = 'M';
			parameters->map[y][x] = '0';
		}
		move_east_2(x, y, parameters);
	}
}

//second part of the previous function
void	move_east_2(int x, int y, t_parameters *parameters)
{
	parameters->mlx.p_facing = 2;
	if (parameters->map[y][x + 1] != '1')
	{
		if (parameters->map[y][x + 1] == '0')
		{
			parameters->map[y][x + 1] = 'P';
			if (parameters->map[y][x] == 'M')
				parameters->map[y][x] = 'E';
			else
				parameters->map[y][x] = '0';
		}
		ft_printf("Movements: %d\n", ++parameters->orange_movement);
	}
}

//function for moving the player to the left
void	move_west(int x, int y, t_parameters *parameters)
{
	parameters->mlx.p_facing = 3;
	if (parameters->map[y][x - 1] != '1')
	{
		if (parameters->map[y][x - 1] == 'C')
		{
			parameters->c--;
			parameters->map[y][x - 1] = 'P';
			if (parameters->map[y][x] == 'M')
				parameters->map[y][x] = 'E';
			else
				parameters->map[y][x] = '0';
		}
		if (parameters->map[y][x - 1] == 'E')
		{
			if (parameters->c == 0)
				win_diesel(parameters);
			parameters->map[y][x - 1] = 'M';
			parameters->map[y][x] = '0';
		}
		move_west_2(x, y, parameters);
	}
}

//second part of the previous function
void	move_west_2(int x, int y, t_parameters *parameters)
{
	parameters->mlx.p_facing = 3;
	if (parameters->map[y][x - 1] != '1')
	{
		if (parameters->map[y][x - 1] == '0')
		{
			parameters->map[y][x - 1] = 'P';
			if (parameters->map[y][x] == 'M')
				parameters->map[y][x] = 'E';
			else
				parameters->map[y][x] = '0';
		}
		ft_printf("Movements: %d\n", ++parameters->orange_movement);
	}
}
