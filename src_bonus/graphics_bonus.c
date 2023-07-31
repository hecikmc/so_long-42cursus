/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:26:19 by jmerchan          #+#    #+#             */
/*   Updated: 2023/04/12 12:56:28 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_deletetextures(t_game *game)
{
	mlx_delete_texture(game->t_floor);
	mlx_delete_texture(game->t_wall);
	mlx_delete_texture(game->t1_player);
	mlx_delete_texture(game->t2_player);
	mlx_delete_texture(game->t1left_player);
	mlx_delete_texture(game->t2left_player);
	mlx_delete_texture(game->t_exit);
	mlx_delete_texture(game->t_collect);
	mlx_delete_texture(game->t_enemy);
}

void	ft_openwindow(t_game *game)
{
	game->mlx = mlx_init(game->col * SPR, game->rows * SPR, "so_long", false);
	game->img = mlx_new_image(game->mlx, game->col * SPR, game->rows * SPR);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	game->text = NULL;
	game->t_floor = mlx_load_png("img/floor.png");
	game->t_wall = mlx_load_png("img/wall.png");
	game->t1_player = mlx_load_png("img/player1.png");
	game->t2_player = mlx_load_png("img/player2.png");
	game->t1left_player = mlx_load_png("img/player1left.png");
	game->t2left_player = mlx_load_png("img/player2left.png");
	game->t_exit = mlx_load_png("img/exit.png");
	game->t_collect = mlx_load_png("img/collect.png");
	game->t_enemy = mlx_load_png("img/enemy.png");
}

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
			else if (game->readmap[y][x] == 'C')
				ft_drawelement(game, game->t_collect, x, y);
			else if (game->readmap[y][x] == 'E')
				ft_drawelement(game, game->t_exit, x, y);
			else if (game->readmap[y][x] == 'P' || game->readmap[y][x] == 'F')
				ft_drawcharacters(game, game->readmap[y][x], x, y);
			x++;
		}
		y++;
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
			else if (game->readmap[y][x] == 'P' || game->readmap[y][x] == 'F')
				ft_drawcharacters(game, game->readmap[y][x], x, y);
			else if (game->readmap[y][x] == 'C')
				ft_drawelement(game, game->t_collect, x, y);
			else if (game->readmap[y][x] == 'E')
				ft_drawelement(game, game->t_exit, x, y);
			x++;
		}
		y++;
	}
}
