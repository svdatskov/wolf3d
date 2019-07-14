#ifndef WOLF3D_H
#define WOLF3D_H

#include <stdlib.h>
#include <math.h>
#include "libft/libft.h"
#include "SDL2/SDL.h"

#define WIDTH 1920
#define HEIGHT 1080

typedef struct	s_print {
	double 		posX;
	double 		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	int			stepX;
	int			stepY;
	int			side;
	int			hit;
	int			drawStart;
	int			drawEnd;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			lineHeight;
}				t_print;

typedef struct	s_param {
	int			width;
	int			height;
	int			base_width;
	char		*line;
	char		*name;
	char		**map;
	SDL_Window	*window;
	SDL_Surface	*surface;
	SDL_Event	event;
	int			running;
	int			*data_img;
}				t_param;


void			ft_error(int error);
void			ft_validation(t_param *param);
t_param			*ft_initial(void);
void			ft_readmap(t_param *param);
void			ft_printmap(t_param *param);

#endif
