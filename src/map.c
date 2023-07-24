/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:08:19 by jmerchan          #+#    #+#             */
/*   Updated: 2023/07/24 19:16:57 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_fillmap(t_game *game, int x, int y)
{
	if (game->cp_map[y][x] == 'E')
	{
		game->cp_map[y][x] = '1';
		return ;
	}
	game->cp_map[y][x] = '1';
	if (game->cp_map[y + 1][x] != '1')
		ft_fillmap(game, x, y + 1);
	if (game->cp_map[y - 1][x] != '1')
		ft_fillmap(game, x, y - 1);
	if (game->cp_map[y][x + 1] != '1')
		ft_fillmap(game, x + 1, y);
	if (game->cp_map[y][x - 1] != '1')
		ft_fillmap(game, x - 1, y);
}

void	ft_checkpath(t_game *game)
{
	int	i;

	i = 0;
	ft_fillmap(game, game->xplay, game->yplay);
	while (game->cp_map[i])
	{
		if (ft_strchr(game->cp_map[i], 'E') || ft_strchr(game->cp_map[i], 'C'))
			ft_msgerror(NOT_PLAY);
		i++;
	}
	while (game->cp_map[i])
	{
		free(game->cp_map[i]);
		i++;
	}
	free(game->cp_map);
}

void	ft_readmap(t_game *game)
{
	char	*line;
	char	*totalread;

	totalread = 0;
	line = 0;
	while (1)
	{
		line = get_next_line(game->fd_map);
		if (line == 0)
			break ;
		totalread = ft_strjoinfree(totalread, line);
		free(line);
	}
	if (totalread == 0 || totalread[0] == '\n')
		ft_msgerror("Empty map\n");
	game->readmap = ft_split(totalread, '\n');
	game->cp_map = ft_split(totalread, '\n');
	free(totalread);
	close(game->fd_map);
}
