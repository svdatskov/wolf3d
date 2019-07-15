#include "wolf3d.h"


static void	ft_sdl_initial(t_param *param)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	param->window = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	if (param->window == NULL)
		exit (5);
	param->surface = SDL_GetWindowSurface(param->window);
	param->render = SDL_CreateRenderer(param->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	param->data_img = param->surface->pixels;
}

t_param 	*ft_initial(void)
{
	t_param *param;
	if (!(param = (t_param*)malloc(sizeof(t_param))))
		ft_error(4);
	param->print = (t_print *)malloc(sizeof(t_print));
	param->height = 0;
	param->width = 0;
	param->base_width = 0;
	param->name = NULL;
	param->map = NULL;
	param->running = 1;
	param->time.old_time = 0;
	param->time.time = 0;
	param->print->dirX = -1;
	param->print->dirY = 0;
	param->print->planeX = 0;
	param->print->planeY = 0.66;
	param->time.old_time = param->time.time;
	param->time.time = SDL_GetTicks();
	param->time.frame_time = (param->time.time - param->time.old_time) / 1000.0;
	param->time.move_speed = param->time.frame_time * 7.0;
	param->time.rot_speed = param->time.frame_time * 3.0;
	ft_sdl_initial(param);
	return(param);
}