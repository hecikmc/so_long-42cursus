/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:07:13 by jmerchan          #+#    #+#             */
/*   Updated: 2023/04/12 11:47:13 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_getcharacters(t_game *game, char character, int row, int col)
{
	if (character == 'P')
	{
		game->nplayer++;
		game->xplay = col;
		game->yplay = row;
	}
	else if (character == 'F' && game->enemies == 0)
	{
		game->enemies++;
		game->y_enemy1 = row;
		game->x_enemy1 = col;
		game->dir_enemy1 = 0;
	}
	else if (character == 'F' && game->enemies == 1)
	{
		game->enemies++;
		game->y_enemy2 = row;
		game->x_enemy2 = col;
		game->dir_enemy2 = 1;
	}
	else if (character == 'F' && game->enemies == 2)
		game->enemies++;
	if (game->enemies > 2)
		ft_msgerror("There are too many enemies on the map\n");
}

void	ft_drawmoves(t_game *game)
{
	char	*mov;

	mov = ft_itoa(game->moves);
	mlx_put_string(game->mlx, mov, 22, 20);
	free(mov);
}

void	ft_play(char *map, t_game *game)
{
	ft_checkmap(map, game);
	ft_openwindow(game);
	ft_drawgame(game);
	ft_drawmoves(game);
	if (game->enemies > 0)
	{
		game->time = 0;
		mlx_loop_hook(game->mlx, ft_move_enemy, game);
	}
	mlx_key_hook(game->mlx, ft_movep, game);
	mlx_loop(game->mlx);
}
