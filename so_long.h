#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
// # include "minilibx-linux/mlx.h"
// # include "minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	int		win_height;
	int		win_width;
	int		e_pos_y;
	int		e_pos_x;
	int		pos_y;
	int		pos_x;
	int		coins;
	int		p_count;
	int		e_count;
}	t_game;

void	get_map(char *filename, t_game *window);
void	exit_error(char *error_type);
int	check_borders(char **map, int width, int height);
int	count_objects(char **map, int width, int height, t_game *game);
void	validate_map(t_game *game);


#endif