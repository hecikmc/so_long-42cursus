/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:36 by jmerchan          #+#    #+#             */
/*   Updated: 2023/04/11 17:46:24 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define INVALID_ARGC "You havo to enter 1 map of type .ber\n"
# define INVALID_MAP "Invalid map, It have to be .ber\n"
# define MAP_ACCES "The map doesn't exist or don't have permissions\n"
# define MAP_BORDER "The map is not valid, borders aren't closed.\n"
# define INVALID_CHAR "Invalid characters in map\n"
# define INVALID_NELEMENTS "Invalid numbers of player, collect or exit.\n"
# define NOT_PLAY "The map cannot be played\n"
# define SPR 64

typedef struct s_game
{
	char			*map;
	int				fd_map;
	char			**readmap;
	char			**cp_map;
	int				col;
	int				rows;
	int				nplayer;
	int				xplay;
	int				yplay;
	int				new_x_p;
	int				new_y_p;
	int				ncolec;
	int				nexit;
	int				moves;
	int				dir;
	mlx_t			*mlx;
	mlx_image_t		*wall_i;
	mlx_image_t		*floor_i;
	mlx_image_t		*player_i1;
	mlx_image_t		*player_i2;
	mlx_image_t		*player_i1left;
	mlx_image_t		*player_i2left;
	mlx_image_t		*exit_i;
	mlx_image_t		*collect_i;
	mlx_texture_t	*t_wall;
	mlx_texture_t	*t_floor;
	mlx_texture_t	*t1_player;
	mlx_texture_t	*t2_player;
	mlx_texture_t	*t1left_player;
	mlx_texture_t	*t2left_player;
	mlx_texture_t	*t_exit;
	mlx_texture_t	*t_collect;
}	t_game;

//main.c
void	ft_initstruct(t_game *game);

//game.c
void	ft_play(char *map, t_game *game);
void	ft_drawgame(t_game *game);
void	ft_drawelement(t_game *game, mlx_image_t *elem, int x, int y);

//play.c
void	ft_movep(mlx_key_data_t keydata, void *param);
void	ft_drawgameleft(t_game *game);

//map_checker.c
void	ft_checkmap(char *map, t_game *game);

//error.c
void	ft_msgerror(char *error);
void	ft_free_error(t_game *game);

//map.c
void	ft_readmap(t_game *game);
void	ft_checkpath(t_game *game);

#endif