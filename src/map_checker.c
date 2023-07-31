/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:12:51 by jmerchan          #+#    #+#             */
/*   Updated: 2023/07/24 19:55:25 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*ft_checkmapname(char *map)
{
	char	*ext;
	char	*mapname;
	int		i;
	int		iex;

	ext = ".ber";
	iex = 3;
	mapname = ft_strtrim(map, " ");
	i = ft_strlen(mapname);
	while (iex >= 0)
	{
		if (mapname[--i] != ext[iex--])
		{
			free(mapname);
			ft_msgerror(INVALID_MAP);
		}
	}
	if (access(mapname, R_OK) == -1)
	{
		free(mapname);
		ft_msgerror(MAP_ACCES);
	}
	return (mapname);
}

static void	ft_checkbordersmap(t_game *game)
{
	int	i;

	i = 0;
	while (game->readmap[0][i] != 0)
	{
		if (game->readmap[0][i] != '1'
			|| game->readmap[game->rows - 1][i] != '1')
		{
			free(game->readmap);
			ft_msgerror(MAP_BORDER);
		}
		i++;
	}
	i = 1;
	while (i < game->rows)
	{
		if (game->readmap[i][0] != '1'
			|| game->readmap[i][game->col - 1] != '1')
		{
			free(game->readmap);
			ft_msgerror(MAP_BORDER);
		}
		i++;
	}
}

static void	ft_checkelements(t_game *game)
{
	int	i;
	int	i2;

	i = 0;
	while (++i < game->rows - 1)
	{
		i2 = 0;
		while (++i2 < game->col - 1)
		{
			if (game->readmap[i][i2] == 'P')
			{
				game->nplayer++;
				game->xplay = i2;
				game->yplay = i;
			}
			else if (game->readmap[i][i2] == 'C')
				game->ncolec++;
			else if (game->readmap[i][i2] == 'E')
				game->nexit++;
			else if (game->readmap[i][i2] != '0' && game->readmap[i][i2] != '1')
				ft_msgerror(INVALID_CHAR);
		}
	}
	if (game->nplayer != 1 || game->ncolec < 1 || game->nexit != 1)
		ft_msgerror(INVALID_NELEMENTS);
}

static void	ft_validmap(t_game *game)
{
	int	i;

	i = 0;
	game->col = ft_strlen(game->readmap[0]);
	while (game->readmap[i] != 0)
	{
		if (game->col != ft_strlen(game->readmap[i]))
			ft_msgerror("The map is not symmetrical");
		i++;
	}
	game->rows = i;
	ft_checkbordersmap(game);
	ft_checkelements(game);
}

void	ft_checkmap(char *map, t_game *game)
{
	game->map = ft_checkmapname(map);
	game->fd_map = open(game->map, O_RDONLY);
	ft_readmap(game);
	ft_initstruct(game);
	ft_validmap(game);
	ft_checkpath(game);
}
