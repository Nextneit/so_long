/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:39:26 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 12:19:24 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	image_error(t_game *game)
{
	if (!game->img_clo_chest || !game->img_op_chest || !game->img_floor
		|| !game->img_coin || !game->img_floor || !game->img_wall
		|| !game->img_p_down || !game->img_p_left || !game->img_p_right
		|| !game->img_p_up || !game->text_clo_chest || !game->text_op_chest
		|| !game->text_floor || !game->text_coin || !game->text_wall
		|| !game->text_p_down || !game->text_p_left || !game->text_p_right
		|| !game->text_p_up || !game->text_mob || !game->text_mob2)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	image_to_window_4(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'M')
	{
		if (mlx_image_to_window(game->mlx, game->img_floor, j * SIZE, i * SIZE)
			< 0)
			return (EXIT_FAILURE);
		if (mlx_image_to_window(game->mlx, game->img_mob, j * SIZE, i * SIZE)
			< 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	image_to_window_3(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->img_floor, j * SIZE, i * SIZE)
			< 0)
			return (EXIT_FAILURE);
		if (mlx_image_to_window(game->mlx, game->img_coin, j * SIZE, i * SIZE)
			< 0)
			return (EXIT_FAILURE);
	}
	if (game->map[i][j] == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->img_floor, j * SIZE, i * SIZE)
			< 0)
			return (EXIT_FAILURE);
		if (mlx_image_to_window(game->mlx, game->img_clo_chest, j * SIZE,
				i * SIZE) < 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	image_to_window_2(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->img_floor, j * SIZE, i * SIZE)
			< 0)
			return (EXIT_FAILURE);
		if (mlx_image_to_window(game->mlx, game->img_wall, j * SIZE, i * SIZE)
			< 0)
			return (EXIT_FAILURE);
	}
	if (game->map[i][j] == '0')
		if (mlx_image_to_window(game->mlx, game->img_floor, j * SIZE, i * SIZE)
			< 0)
			return (EXIT_FAILURE);
	if (game->map[i][j] == 'P')
	{
		if (mlx_image_to_window(game->mlx, game->img_floor, j * SIZE, i * SIZE)
			< 0)
			return (EXIT_FAILURE);
		if (mlx_image_to_window(game->mlx, game->img_p_down,
				j * SIZE, i * SIZE) < 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	image_to_window(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->lines)
	{
		j = -1;
		while (++j < game->columns)
		{
			if (image_to_window_2(game, i, j) == 1)
				return (EXIT_FAILURE);
			if (image_to_window_3(game, i, j) == 1)
				return (EXIT_FAILURE);
			if (image_to_window_4(game, i, j) == 1)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
