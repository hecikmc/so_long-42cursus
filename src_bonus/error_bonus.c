/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:17:52 by jmerchan          #+#    #+#             */
/*   Updated: 2023/04/11 17:43:26 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_msgerror(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	exit (EXIT_FAILURE);
}

void	ft_free_error(t_game *game)
{
	int	i;

	i = 0;
	while (game->readmap[i])
		free(game->readmap[i++]);
	free(game->map);
	free(game->readmap);
}
