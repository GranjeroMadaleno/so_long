/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:07:50 by andefern          #+#    #+#             */
/*   Updated: 2024/02/26 12:07:53 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//function that verrifies if the map can be readed
int	ber_size(const char *map_path)
{
	char	c;
	int		i;
	int		reading;
	int		fd;

	i = 0;
	reading = 1;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_matic("Could not open file\n");
	while (reading > 0)
	{
		reading = read(fd, &c, 1);
		if (reading < 0)
			error_matic("Error reading file\n");
		i++;
	}
	close(fd);
	return (--i);
}

//function that initialize the rest of the functions
void	initializer(t_parameters *parameters, const char *map_path)
{
	parameters->orange_movement = 0;
	parameters->map_size = ber_size(map_path);
	get_map_str(parameters, map_path);
	parameters->map = ft_split(parameters->map_str, '\n');
	count_characters(parameters);
	count_rows_and_cols(parameters);
	parameters->map_phill = ft_split(parameters->map_str, '\n');
}
