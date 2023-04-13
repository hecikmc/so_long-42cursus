/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:35:34 by jmerchan          #+#    #+#             */
/*   Updated: 2023/04/12 16:29:15 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_draw(t_game *game)
{
	if (game->dir == 0)
		ft_drawgameleft(game);
	else
		ft_drawgame(game);
}

static void	ft_finishgame(t_game *game)
{
	if (game->ncolec > 0)
		ft_putstr_fd("Aun quedan coleccionables por recoger\n", 1);
	else
	{
		ft_putstr_fd("YOU WIN\n", 1);
		exit (EXIT_SUCCESS);
	}
}

static void	ft_makemove(t_game *game)
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
	}
	else if (game->readmap[game->new_y_p][game->new_x_p] == 'E')
		ft_finishgame(game);
	else if (game->readmap[game->new_y_p][game->new_x_p] == 'F')
	{
		ft_putstr_fd("YOU LOSE\n", 1);
		exit (1);
	}	
	ft_draw(game);
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
	ft_drawmoves(game);
	return ;
}

void	ft_drawcharacters(t_game *game, char character, int x, int y)
{
	if (character == 'P' && game->moves % 2 == 0)
	{
		if (game->dir == 1)
			ft_drawelement(game, game->player_i1, x, y);
		else
			ft_drawelement(game, game->player_i1left, x, y);
	}
	else if (character == 'P' && game->moves % 2 != 0)
	{
		if (game->dir == 1)
			ft_drawelement(game, game->player_i2, x, y);
		else
			ft_drawelement(game, game->player_i2left, x, y);
	}
	else if (character == 'F')
		ft_drawelement(game, game->enemy_i, x, y);
}
