/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 22:03:10 by sdatskov          #+#    #+#             */
/*   Updated: 2019/07/18 22:03:12 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "SDL2/SDL.h"
# include "SDL2_image/SDL_image.h"
# include "SDL2_ttf/SDL_ttf.h"

# define WIDTH		1920
# define HEIGHT		1080
# define T_WIDTH 	64
# define T_HEIGHT 	64

# define KEYDOWN		p->event.type == SDL_KEYDOWN
# define KEYUP		p->event.type == SDL_KEYUP
# define PR			p->pr
# define TM			p->time

typedef struct		s_print {
	double			p_x;
	double			p_y;
	double			d_x;
	double			od_x;
	double			d_y;
	double			pl_x;
	double			opl_x;
	double			pl_y;
	double			cam_x;
	double			ray_x;
	double			ray_y;
	double			sd_x;
	double			sd_y;
	double			dlt_x;
	double			dlt_y;
	double			pwd;
	int				map_y;
	int				map_x;
	int				st_x;
	int				st_y;
	int				side;
	int				hit;
	int				dr_s;
	int				dr_e;
	int				line_h;
}					t_print;

typedef struct		s_time {
	double			time;
	double			old_time;
	double			fr_t;
	double			mv_s;
	double			ro_s;
}					t_time;

typedef struct		s_flags {
	int				up;
	int				down;
	int				left;
	int				right;
	int				speed;
	int				textures;
}					t_flags;

typedef struct		s_textur {
	double			text_wall;
	int				text_x;
	int				text_y;
	int				b;
	int				color;
}					t_textur;

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
	int				*img;
	struct s_flags	flags;
	struct s_time	time;
	struct s_print	*pr;
}					t_param;

void				ft_error(int error);
void				ft_validation(t_param *param);
void				ft_readmap(t_param *param);
void				ft_printmap(t_param *p);
t_time				ft_hooks(t_param *param);
t_param				*ft_initial(void);
t_param				*ft_events(t_param *param);
void				ft_sides(t_param *param);
t_textur			draw_texture(t_param *p);
t_textur			draw_wall(t_param *p, t_textur t, int y, int x);

#endif
