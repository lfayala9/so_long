#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*background;
	void	*coin;
	void	*player;
	char	**map;
	int		win_height;
	int		win_width;
	int		e_pos_y;
	int		e_pos_x;
	int		pos_x;
	int		pos_y;
	int		coins;
	int		p_count;
	int		e_count;
}	t_game;

void	get_map(char *filename, t_game *window);
void	count_objects(char **map, int width, int height, t_game *game);
void 	free_map(t_game *win);
void	exit_error(char *error_type, t_game *game);
void	validate_map(t_game *game);
int		get_line_count(char *filename);
int		check_objects(t_game *game, char object);
void	flood_fill(int pos_x, int pos_y, t_game *game, int **visited);
int		check_extension(char *filename, char *extension);
#endif