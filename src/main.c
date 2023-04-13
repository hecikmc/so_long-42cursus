/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:57:36 by jmerchan          #+#    #+#             */
/*   Updated: 2023/04/11 13:45:12 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Written by Bruh

#include "../include/so_long.h"

void	ft_initstruct(t_game *game)
{
	game->nplayer = 0;
	game->ncolec = 0;
	game->nexit = 0;
	game->moves = 0;
	game->dir = 1;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_msgerror(INVALID_ARGC);
	ft_play(argv[1], &game);
	ft_free_error(&game);
	return (EXIT_SUCCESS);
}
