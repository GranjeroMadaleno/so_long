/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:12:34 by andefern          #+#    #+#             */
/*   Updated: 2024/02/27 11:50:41 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//function that reads the string with the content of the map
void	get_map_str(t_parameters *parameters, const char *map_path)
{
	int		reading;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_matic("Could not open file\n");
	parameters->map_str = malloc(sizeof(char) * parameters->map_size + 1);
	reading = read(fd, parameters->map_str, parameters->map_size);
	if (reading < 0)
		error_matic("Error reading file\n");
	if (parameters->map_size < 16)
	{
		free(parameters->map_str);
		error_matic("Insufficient map size\n");
	}
	parameters->map_str[parameters->map_size] = '\0';
	close(fd);
}
