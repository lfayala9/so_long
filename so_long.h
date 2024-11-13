#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*img;
	char	*add;
	int		bit_pixel;
	int		line_len;
	int		endian;
}	t_data;

int	get_width(int fd);

#endif