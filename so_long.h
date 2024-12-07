/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:38:22 by layala-s          #+#    #+#             */
/*   Updated: 2024/12/07 02:38:24 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define ESC 65307
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

typedef struct s_object
{
	void	*player;
	void	*coin;
	void	*wall;
	void	*exit;
	void	*background;
}	t_object;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			win_height;
	int			win_width;
	int			e_pos_y;
	int			e_pos_x;
	int			p_pos_x;
	int			p_pos_y;
	int			coins;
	int			p_count;
	int			e_count;
	int			is_collected;
	int			steps;
	char		**map;
	t_object	*object;
}	t_game;

void	get_map(char *filename, t_game *window);
void	count_objects(char **map, int width, int height, t_game *game);
void	free_map(t_game *win);
void	exit_error(char *error_type, t_game *game);
void	validate_map(t_game *game);
void	free_images(t_game *game);
int		hooks(int key, t_game *game);
int		get_line_count(char *filename);
int		check_objects(t_game *game, char object);
void	flood_fill(int pos_x, int pos_y, t_game *game, int **visited);
int		exit_game(t_game *game);
int		check_extension(char *filename, char *extension);
void	render_game(t_game *game);
void	free_game(t_game *game);

#endif
