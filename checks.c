/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:01:17 by andefern          #+#    #+#             */
/*   Updated: 2024/02/27 11:53:35 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//function that verifies if the file ends with .ber
void	is_ber_file(const char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (file_name[len - 1] != 'r')
		error_matic(".ber not found\n");
	if (file_name[len - 2] != 'e')
		error_matic(".ber not found\n");
	if (file_name[len - 3] != 'b')
		error_matic(".ber not found\n");
	if (file_name[len - 4] != '.' || file_name[0] == '.')
		error_matic(".ber not found\n");
}

//function that checks if walls close
void	check_walls(t_parameters *parameters)
{
	int	i;
	int	q;

	i = 0;
	while (parameters->map[i] != NULL)
	{
		q = 0;
		while (parameters->map[i][q])
		{
			if (q == 0 && parameters->map[i][q] != '1')
				error_matic("Not closed borderline (meringue meringue)\n");
			if (i == 0 && parameters->map[i][q] != '1')
				error_matic("Not closed borderline (meringue meringue)\n");
			if (q == parameters->cols - 1 \
			&& parameters->map[i][q] != '1')
				error_matic("Not closed borderline (meringue meringue)\n");
			if (i == parameters->rows - 1 \
			&& parameters->map[i][q] != '1')
				error_matic("Not closed borderline (meringue meringue)\n");
			q++;
		}
		i++;
	}
}

//function fo checking parameter quantities
void	check_chars(t_parameters *parameters)
{
	if (parameters->p < 1)
		error_matic("Player not found\n");
	if (parameters->p > 1)
		error_matic("Too many players found\n");
	if (parameters->e < 1)
		error_matic("Exit not found\n");
	if (parameters->e > 1)
		error_matic("Too many exits found\n");
	if (parameters->c < 1)
		error_matic("Not a single coin found\n");
}

//function that garantizes that the map is playable
void	gar_phill(t_parameters *parameters)
{
	int	i;
	int	q;

	i = 0;
	while (parameters->map_phill[i] != NULL)
	{
		q = 0;
		while (parameters->map_phill[i][q] != '\0')
		{
			if (parameters->map_phill[i][q] != '1' \
			&& parameters->map_phill[i][q] != '0')
				error_matic("The map is not playable\n");
			q++;
		}
		i++;
	}
}

//function that checks the map
void	checkster_cheetos(t_parameters *parameters)
{
	check_chars(parameters);
	check_walls(parameters);
	flud_phill(parameters, y_for_p(parameters), x_for_p(parameters));
	gar_phill(parameters);
}
