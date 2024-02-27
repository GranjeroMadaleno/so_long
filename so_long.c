/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:10:36 by andefern          #+#    #+#             */
/*   Updated: 2024/02/27 12:46:31 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//program's principal function
int	main(int argc, char const *argv[])
{
	t_parameters	parameters;

	if (argc < 2)
		error_matic("Not map provided\n");
	if (argc > 2)
		error_matic("Too many arguments\n");
	initializer(&parameters, argv[1]);
	checkster_cheetos(&parameters);
	mlx_starter_pack(&parameters);
}
