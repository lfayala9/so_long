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
	int	win_height;
	int	win_width;
}	t_game;

void	set_dimensions(char *filename, t_game *window);
void	exit_error(char *error_type);

#endif