/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:41:10 by jmerchan          #+#    #+#             */
/*   Updated: 2023/04/12 16:17:28 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	ft_movegosht1_rigth(t_game *game)
{
	if (game->readmap[game->y_enemy1][game->x_enemy1 + 1] == '1'
		|| game->readmap[game->y_enemy1][game->x_enemy1 + 1] == 'C'
		|| game->readmap[game->y_enemy1][game->x_enemy1 + 1] == 'E'
		|| game->readmap[game->y_enemy1][game->x_enemy1 + 1] == 'F')
	{
		game->dir_enemy1 = 0;
		return ;
	}
	else if (game->readmap[game->y_enemy1][game->x_enemy1 + 1] == '0')
	{
		game->readmap[game->y_enemy1][game->x_enemy1] = '0';
		game->readmap[game->y_enemy1][game->x_enemy1 + 1] = 'F';
		game->x_enemy1++;
	}
	else if (game->readmap[game->y_enemy1][game->x_enemy1 + 1] == 'P')
	{
		ft_putstr_fd("YOU LOSE\n", 1);
		exit (1);
	}
}

static void	ft_movegosht1_left(t_game *game)
{
	if (game->readmap[game->y_enemy1][game->x_enemy1 - 1] == '1'
		|| game->readmap[game->y_enemy1][game->x_enemy1 - 1] == 'C'
		|| game->readmap[game->y_enemy1][game->x_enemy1 - 1] == 'E'
		|| game->readmap[game->y_enemy1][game->x_enemy1 - 1] == 'F')
	{
		game->dir_enemy1 = 1;
		return ;
	}
	else if (game->readmap[game->y_enemy1][game->x_enemy1 - 1] == '0')
	{
		game->readmap[game->y_enemy1][game->x_enemy1] = '0';
		game->readmap[game->y_enemy1][game->x_enemy1 - 1] = 'F';
		game->x_enemy1--;
	}
	else if (game->readmap[game->y_enemy1][game->x_enemy1 - 1] == 'P')
	{
		ft_putstr_fd("YOU LOSE\n", 1);
		exit (1);
	}
}

static void	ft_movegosht2_rigth(t_game *game)
{
	if (game->readmap[game->y_enemy2][game->x_enemy2 + 1] == '1'
		|| game->readmap[game->y_enemy2][game->x_enemy2 + 1] == 'C'
		|| game->readmap[game->y_enemy2][game->x_enemy2 + 1] == 'E'
		|| game->readmap[game->y_enemy2][game->x_enemy2 + 1] == 'F')
	{
		game->dir_enemy2 = 0;
		return ;
	}
	else if (game->readmap[game->y_enemy2][game->x_enemy2 + 1] == '0')
	{
		game->readmap[game->y_enemy2][game->x_enemy2] = '0';
		game->readmap[game->y_enemy2][game->x_enemy2 + 1] = 'F';
		game->x_enemy2++;
	}
	else if (game->readmap[game->y_enemy2][game->x_enemy2 + 1] == 'P')
	{
		ft_putstr_fd("YOU LOSE\n", 1);
		exit (1);
	}
}

static void	ft_movegosht2_left(t_game *game)
{
	if (game->readmap[game->y_enemy2][game->x_enemy2 - 1] == '1'
		|| game->readmap[game->y_enemy2][game->x_enemy2 - 1] == 'C'
		|| game->readmap[game->y_enemy2][game->x_enemy2 - 1] == 'E'
		|| game->readmap[game->y_enemy2][game->x_enemy2 - 1] == 'F')
	{
		game->dir_enemy2 = 1;
		return ;
	}
	else if (game->readmap[game->y_enemy2][game->x_enemy2 - 1] == '0')
	{
		game->readmap[game->y_enemy2][game->x_enemy2] = '0';
		game->readmap[game->y_enemy2][game->x_enemy2 - 1] = 'F';
		game->x_enemy2--;
	}
	else if (game->readmap[game->y_enemy2][game->x_enemy2 - 1] == 'P')
	{
		ft_putstr_fd("YOU LOSE\n", 1);
		exit (1);
	}
}

void	ft_move_enemy(void *param)
{
	t_game	*game;

	game = param;
	game->time += game->mlx->delta_time;
	if (game->time > 0.4)
	{
		if (game->enemies > 0)
		{
			if (game->dir_enemy1 == 0)
				ft_movegosht1_left(game);
			else
				ft_movegosht1_rigth(game);
		}
		if (game->enemies > 1)
		{
			if (game->dir_enemy2 == 0)
				ft_movegosht2_left(game);
			else
				ft_movegosht2_rigth(game);
		}
		ft_draw(game);
		game->time = 0;
		ft_drawmoves(game);
	}
}
