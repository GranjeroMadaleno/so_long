/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_locators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:06:02 by andefern          #+#    #+#             */
/*   Updated: 2024/02/26 12:20:08 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//function that locates P's position respect y
int	y_for_p(t_parameters *parameters)
{
	int	i;

	i = 0;
	while (parameters->map[i] != NULL)
	{
		if (ft_strchr(parameters->map[i], 'P') != NULL || \
		ft_strchr(parameters->map[i], 'M') != NULL)
			return (i);
		i++;
	}
	return (0);
}

//function that locates P's position respect x
int	x_for_p(t_parameters *parameters)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (parameters->map[i] != NULL)
	{
		if (ft_strchr(parameters->map[i], 'P') != NULL || \
		ft_strchr(parameters->map[i], 'M') != NULL)
		{
			while (parameters->map[i][j] != 'P' && \
			parameters->map[i][j] != 'M')
				j++;
			return (j);
		}
		i++;
	}
	return (0);
}
