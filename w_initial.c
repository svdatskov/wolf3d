#include "wolf3d.h"


static void	ft_sdl_initial(t_param *param)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	param->window = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	if (param->window == NULL)
		exit (5);
	param->surface = SDL_GetWindowSurface(param->window);
	param->data_img = param->surface->pixels;
}

t_param 	*ft_initial(void)
{
	t_param *param;
	if (!(param = (t_param*)malloc(sizeof(t_param))))
		ft_error(4);
	param->pr = (t_print *)malloc(sizeof(t_print));
	param->height = 0;
	param->width = 0;
	param->base_width = 0;
	param->name = NULL;
	param->map = NULL;
	param->running = 1;
	param->time.old_time = 0;
	param->time.time = 0;
	param->pr->d_x = -1;
	param->pr->d_y = 0;
	param->pr->pl_x = 0;
	param->pr->pl_y = 0.66;
	param->time.old_time = param->time.time;
	param->time.time = SDL_GetTicks();
	param->time.fr_t = (param->time.time - param->time.old_time) / 1000.0;
	param->time.mv_s = param->time.fr_t * 7.0;
	param->time.ro_s = param->time.fr_t * 3.0;
	ft_sdl_initial(param);
	return(param);
}