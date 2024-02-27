/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flud_phill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:07:19 by andefern          #+#    #+#             */
/*   Updated: 2024/02/26 12:07:01 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//function for filling the map with flood_fill
void	flud_phill(t_parameters *parameters, int y, int x)
{
	if (parameters->map_phill[y][x] == '1')
		return ;
	parameters->map_phill[y][x] = '1';
	flud_phill(parameters, y - 1, x);
	flud_phill(parameters, y + 1, x);
	flud_phill(parameters, y, x + 1);
	flud_phill(parameters, y, x - 1);
}
