#ifndef WOLF3D_H
#define WOLF3D_H

#include <stdlib.h>
#include <math.h>
#include "libft/libft.h"
#include "SDL2/SDL.h"

#define WIDTH	1920
#define HEIGHT	1080

typedef struct		s_print {
	double 			posX;
	double 			posY;
	double			dirX;
	double 			olddirX;
	double			dirY;
	double 			olddirY;
	double			planeX;
	double 			oldplaneX;
	double			planeY;
	double 			oldplaneY;
	double			cameraX;
	double			rayDirX;
	double			rayDirY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	double			perpWallDist;
	int				mapX;
	int				mapY;
	int				stepX;
	int				stepY;
	int				side;
	int				hit;
	int				drawStart;
	int				drawEnd;
	int				lineHeight;
}					t_print;

typedef struct		s_time {
	double 			time;
	double 			old_time;
	double 			frame_time;
	double 			move_speed;
	double 			rot_speed;
}					t_time;

typedef struct		s_param {
	SDL_Window		*window;
	SDL_Surface		*surface;
	SDL_Renderer	*render;
	SDL_Event		event;
	int				width;
	int				height;
	int				base_width;
	int				running;
	int				*data_img;
	char			*line;
	char			*name;
	char			**map;
	struct s_time 	time;
	struct s_print  *print;
}					t_param;

void			ft_error(int error);
void			ft_validation(t_param *param);
void			ft_readmap(t_param *param);
void			ft_printmap(t_param *param);
t_time			ft_hooks(t_param *param);
t_param			*ft_initial(void);

#endif
