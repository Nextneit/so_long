/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:50:37 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 12:19:10 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_format(char *map_name)
{
	int	i;

	i = 0;
	i = ft_strlen(map_name);
	if ((map_name[i - 1] == 'r' && map_name[i - 2] == 'e')
		&& (map_name[i - 3] == 'b' && map_name[i - 4] == '.'))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

static int	check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->lines - 1;
	while (game->map[0][i] != '\0')
	{
		if (game->map[0][i] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (game->map[j][i] != '\0')
	{
		if (game->map[j][i] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	i--;
	while (j-- > 0)
	{
		if (game->map[j][0] != '1' || game->map[j][i] != '1')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->lines;
	while (--j >= 0)
	{
		while (game->map[j][i] != '\0')
		{
			if (game->map[j][i] != '1' && game->map[j][i] != '0'
				&& game->map[j][i] != 'C' && game->map[j][i] != 'P'
					&& game->map[j][i] != 'E' && game->map[j][i] != 'M')
				return (EXIT_FAILURE);
			i++;
		}
		i = 0;
	}
	return (EXIT_SUCCESS);
}

static int	count_objects(t_game *game)
{
	int	i;
	int	j;

	j = game->lines;
	while (--j > 0)
	{
		i = -1;
		while (game->map[j][++i] != '\0')
		{
			if (game->map[j][i] == 'C')
				game->coin++;
			else if (game->map[j][i] == 'P')
			{
				game->player++;
				game->p_position.x = i;
				game->p_position.y = j;
			}
			else if (game->map[j][i] == 'E')
				game->exit++;
		}
	}
	if (game->coin == 0 || game->player != 1 || game->exit != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->lines;
	i = ft_strlen(game->map[0]);
	while (--j >= 0)
		if (i != ft_strlen(game->map[j]))
			return (ft_printf("Error: Mapa no rectangular\n"), EXIT_FAILURE);
	if (count_objects(game) == 1)
		return (ft_printf("Error: Numero de elementos erroneo\n"),
			EXIT_FAILURE);
	if (check_elements(game) == 1)
		return (ft_printf("Error: Elemento erroneo\n"), EXIT_FAILURE);
	if (check_wall(game) == 1)
		return (ft_printf("Error: Mapa no rodeado de muros\n"), EXIT_FAILURE);
	valid_way(game, (t_point){game->columns, game->lines}, game->p_position);
	if (game->coin != game->coin_copy || game->exit != game->exit_copy)
		return (ft_printf("Error: Camino no valido\n"), EXIT_FAILURE);
	game->coin = 0;
	return (EXIT_SUCCESS);
}
