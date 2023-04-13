/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:36 by jmerchan          #+#    #+#             */
/*   Updated: 2023/04/12 16:25:31 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	int				x_enemy1;
	int				y_enemy1;
	int				dir_enemy1;
	int				x_enemy2;
	int				y_enemy2;
	int				dir_enemy2;
	int				ncolec;
	int				nexit;
	int				enemies;
	int				moves;
	int				dir;
	double			time;
	mlx_t			*mlx;
	mlx_image_t		*wall_i;
	mlx_image_t		*floor_i;
	mlx_image_t		*player_i1;
	mlx_image_t		*player_i2;
	mlx_image_t		*player_i1left;
	mlx_image_t		*player_i2left;
	mlx_image_t		*exit_i;
	mlx_image_t		*collect_i;
	mlx_image_t		*enemy_i;
	mlx_texture_t	*t_wall;
	mlx_texture_t	*t_floor;
	mlx_texture_t	*t1_player;
	mlx_texture_t	*t2_player;
	mlx_texture_t	*t1left_player;
	mlx_texture_t	*t2left_player;
	mlx_texture_t	*t_exit;
	mlx_texture_t	*t_collect;
	mlx_texture_t	*t_enemy;
}	t_game;

typedef struct s_enemy
{
	int	x_enemy;
	int	y_enemy;
	int	dir;
}	t_enemy;

//main_bonus.c
void	ft_initstruct(t_game *game);

//game_bonus.c
void	ft_play(char *map, t_game *game);
void	ft_getcharacters(t_game *game, char character, int row, int col);
void	ft_drawmoves(t_game *game);

//play_bonus.c
void	ft_movep(mlx_key_data_t keydata, void *param);
void	ft_drawcharacters(t_game *game, char character, int x, int y);
void	ft_draw(t_game *game);

//map_bonus.c
void	ft_readmap(t_game *game);
void	ft_checkpath(t_game *game);

//map_checker_bonus.c
void	ft_checkmap(char *map, t_game *game);

//graphics.c
void	ft_deletetextures(t_game *game);
void	ft_openwindow(t_game *game);
void	ft_drawelement(t_game *game, mlx_image_t *elem, int x, int y);
void	ft_drawgame(t_game *game);
void	ft_drawgameleft(t_game *game);

//enemy_bonus.c
void	ft_move_enemy(void *param);

//error_bonus.c
void	ft_msgerror(char *error);
void	ft_free_error(t_game *game);

#endif