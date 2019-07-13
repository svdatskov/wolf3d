#ifndef WOLF3D_H
#define WOLF3D_H

#include <stdlib.h>
#include "libft/libft.h"
#include "SDL2/SDL.h"

#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_param {
	int width;
	int height;
	int base_width;
	char *line;
	char *name;
	char **map;
}				t_param;

void	ft_error(int error);
t_param	ft_validation(t_param param);

#endif
