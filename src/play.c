/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:35:34 by jmerchan          #+#    #+#             */
/*   Updated: 2023/04/11 13:37:42 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_finishgame(t_game *game)
{
	if (game->ncolec > 0)
		ft_putstr_fd("Aun quedan coleccionables por recoger\n", 1);
	else
	{
		ft_putstr_fd("YOU WIN\n", 1);
		exit (EXIT_SUCCESS);
	}
}

void	ft_drawgameleft(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->col)
		{
			if (game->readmap[y][x] == '0')
				ft_drawelement(game, game->t_floor, x, y);
			else if (game->readmap[y][x] == '1')
				ft_drawelement(game, game->t_wall, x, y);
			else if (game->readmap[y][x] == 'P' && game->moves % 2 == 0)
				ft_drawelement(game, game->t1left_player, x, y);
			else if (game->readmap[y][x] == 'P' && game->moves % 2 != 0)
				ft_drawelement(game, game->t2left_player, x, y);
			else if (game->readmap[y][x] == 'C')
				ft_drawelement(game, game->t_collect, x, y);
			else if (game->readmap[y][x] == 'E')
				ft_drawelement(game, game->t_exit, x, y);
			x++;
		}
		y++;
	}
}

void	ft_makemove(t_game *game)
{
	if (game->readmap[game->new_y_p][game->new_x_p] == 'C')
		game->ncolec--;
	if (game->readmap[game->new_y_p][game->new_x_p] == 'C' ||
		game->readmap[game->new_y_p][game->new_x_p] == '0')
	{
		game->readmap[game->yplay][game->xplay] = '0';
		game->readmap[game->new_y_p][game->new_x_p] = 'P';
		game->xplay = game->new_x_p;
		game->yplay = game->new_y_p;
		game->moves++;
		ft_putstr_fd("Total moves: ", 1);
		ft_putnbr_fd(game->moves, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (game->readmap[game->new_y_p][game->new_x_p] == 'E')
		ft_finishgame(game);
	if (game->dir == 0)
		ft_drawgameleft(game);
	else
		ft_drawgame(game);
}

void	ft_movep(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	game->new_y_p = game->yplay;
	game->new_x_p = game->xplay;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		game->new_y_p--;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
	{
		game->new_x_p--;
		game->dir = 0;
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
	{
		game->dir = 1;
		game->new_x_p++;
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		game->new_y_p++;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		exit(0);
	ft_makemove(game);
	return ;
}
