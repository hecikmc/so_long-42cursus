/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:07:13 by jmerchan          #+#    #+#             */
/*   Updated: 2023/04/11 13:41:41 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_drawelement(t_game *game, mlx_texture_t *elem, int x, int y)
{
	mlx_draw_texture(game->img, elem, (x * SPR), (y * SPR));
}

void	ft_drawgame(t_game *game)
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
				ft_drawelement(game, game->t1_player, x, y);
			else if (game->readmap[y][x] == 'P' && game->moves % 2 != 0)
				ft_drawelement(game, game->t2_player, x, y);
			else if (game->readmap[y][x] == 'C')
				ft_drawelement(game, game->t_collect, x, y);
			else if (game->readmap[y][x] == 'E')
				ft_drawelement(game, game->t_exit, x, y);
			x++;
		}
		y++;
	}
}

static void	ft_openwindow(t_game *game)
{
	game->mlx = mlx_init(game->col * SPR, game->rows * SPR, "so_long", false);
	game->img = mlx_new_image(game->mlx, game->col * SPR, game->rows * SPR);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	game->t_floor = mlx_load_png("img/floor.png");
	game->t_wall = mlx_load_png("img/wall.png");
	game->t1_player = mlx_load_png("img/player1.png");
	game->t2_player = mlx_load_png("img/player2.png");
	game->t1left_player = mlx_load_png("img/player1left.png");
	game->t2left_player = mlx_load_png("img/player2left.png");
	game->t_exit = mlx_load_png("img/exit.png");
	game->t_collect = mlx_load_png("img/collect.png");
}

void	ft_play(char *map, t_game *game)
{
	ft_checkmap(map, game);
	ft_openwindow(game);
	ft_drawgame(game);
	mlx_key_hook(game->mlx, &ft_movep, game);
	mlx_loop(game->mlx);
}
