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

void	ft_drawelement(t_game *game, mlx_image_t *elem, int x, int y)
{
	mlx_image_to_window(game->mlx, elem, (x * SPR), (y * SPR));
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
				ft_drawelement(game, game->floor_i, x, y);
			else if (game->readmap[y][x] == '1')
				ft_drawelement(game, game->wall_i, x, y);
			else if (game->readmap[y][x] == 'P' && game->moves % 2 == 0)
				ft_drawelement(game, game->player_i1, x, y);
			else if (game->readmap[y][x] == 'P' && game->moves % 2 != 0)
				ft_drawelement(game, game->player_i2, x, y);
			else if (game->readmap[y][x] == 'C')
				ft_drawelement(game, game->collect_i, x, y);
			else if (game->readmap[y][x] == 'E')
				ft_drawelement(game, game->exit_i, x, y);
			x++;
		}
		y++;
	}
}

static void	ft_openwindow(t_game *game)
{
	game->mlx = mlx_init(game->col * SPR, game->rows * SPR, "so_long", false);
	game->t_floor = mlx_load_png("img/floor.png");
	game->t_wall = mlx_load_png("img/wall.png");
	game->t1_player = mlx_load_png("img/player1.png");
	game->t2_player = mlx_load_png("img/player2.png");
	game->t1left_player = mlx_load_png("img/player1left.png");
	game->t2left_player = mlx_load_png("img/player2left.png");
	game->t_exit = mlx_load_png("img/exit.png");
	game->t_collect = mlx_load_png("img/collect.png");
	game->floor_i = mlx_texture_to_image(game->mlx, game->t_floor);
	game->wall_i = mlx_texture_to_image(game->mlx, game->t_wall);
	game->player_i1 = mlx_texture_to_image(game->mlx, game->t1_player);
	game->player_i2 = mlx_texture_to_image(game->mlx, game->t2_player);
	game->player_i1left = mlx_texture_to_image(game->mlx, game->t1left_player);
	game->player_i2left = mlx_texture_to_image(game->mlx, game->t2left_player);
	game->exit_i = mlx_texture_to_image(game->mlx, game->t_exit);
	game->collect_i = mlx_texture_to_image(game->mlx, game->t_collect);
	mlx_delete_texture(game->t_floor);
	mlx_delete_texture(game->t_wall);
	mlx_delete_texture(game->t1_player);
	mlx_delete_texture(game->t2_player);
	mlx_delete_texture(game->t1left_player);
	mlx_delete_texture(game->t2left_player);
	mlx_delete_texture(game->t_exit);
	mlx_delete_texture(game->t_collect);
}

void	ft_play(char *map, t_game *game)
{
	ft_checkmap(map, game);
	ft_openwindow(game);
	ft_drawgame(game);
	mlx_key_hook(game->mlx, &ft_movep, game);
	mlx_loop(game->mlx);
}
