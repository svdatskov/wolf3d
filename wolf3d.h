#ifndef WOLF3D_H
#define WOLF3D_H

#include <stdlib.h>
#include <math.h>
#include "libft/libft.h"
#include "SDL2/SDL.h"
#include "Frameworks/SDL2_image.framework/Headers/SDL_image.h"

#define WIDTH		1920
#define HEIGHT		1080
#define T_WIDTH 	64
#define T_HEIGHT 	64

typedef struct		s_print {
	double 			p_x;
	double 			p_y;
	double			d_x;
	double 			od_X;
	double			d_y;
	double			pl_x;
	double 			opl_x;
	double			pl_y;
	double			cam_x;
	double			ray_x;
	double			ray_y;
	double			sd_x;
	double			sd_y;
	double			dlt_x;
	double			dlt_y;
	double			pwd;
	int				mapX;
	int				mapY;
	int				st_x;
	int				st_y;
	int				side;
	int				hit;
	int				drS;
	int				drE;
	int				lineHeight;
}					t_print;

typedef struct		s_time {
	double 			time;
	double 			old_time;
	double 			fr_t;
	double 			mv_s;
	double 			ro_s;
}					t_time;

typedef struct		s_flags {
	int 			up;
	int 			down;
	int 			left;
	int 			right;
}					t_flags;

typedef struct		s_param {
	SDL_Window		*window;
	SDL_Surface		*surface;
	SDL_Surface		**image;
	SDL_Event		event;
	int				width;
	int				height;
	int				base_width;
	int				running;
	int				*data_img;
	char			*line;
	char			*name;
	char			**map;
	int 			*img;
	struct s_flags  flags;
	struct s_time 	time;
	struct s_print  *pr;
}					t_param;

void			ft_error(int error);
void			ft_validation(t_param *param);
void			ft_readmap(t_param *param);
void			ft_printmap(t_param *p);
t_time			ft_hooks(t_param *param);
t_param			*ft_initial(void);
t_param			*ft_events(t_param *param);

#endif
