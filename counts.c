/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:04:59 by andefern          #+#    #+#             */
/*   Updated: 2024/02/27 10:18:52 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//function that counts the obligatory parameters
void	count_characters(t_parameters *parameters)
{
	int	i;

	i = 0;
	parameters->c = 0;
	parameters->p = 0;
	parameters->e = 0;
	while (i < parameters->map_size)
	{
		if (parameters->map_str[i] == 'P')
			parameters->p++;
		else if (parameters->map_str[i] == 'C')
			parameters->c++;
		else if (parameters->map_str[i] == 'E')
			parameters->e++;
		else if (parameters->map_str[i] != '1' && \
		parameters->map_str[i] != '0' && parameters->map_str[i] != '\n')
			error_matic("Invalid character\n");
		else if (parameters->map_str[i] == '\n' && i == 0)
			error_matic("Empty line found\n");
		else if (parameters->map_str[i] == '\n' && \
		parameters->map_str[i + 1] == '\n')
			error_matic("Empty line found\n");
		i++;
	}
}

//function for counting the rows and cols from the map
void	count_rows_and_cols(t_parameters *parameters)
{
	int		i;
	size_t	correct_size;

	i = 0;
	correct_size = 0;
	parameters->rows = 0;
	parameters->cols = 0;
	while (parameters->map[parameters->rows] != NULL)
		parameters->rows++;
	correct_size = ft_strlen(parameters->map[i]);
	while (parameters->map[i])
	{
		if (correct_size != ft_strlen(parameters->map[i]))
			error_matic("Map is not rectangular\n");
		i++;
	}
	parameters->cols = correct_size;
}
