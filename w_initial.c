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
	param->height = 0;
	param->width = 0;
	param->base_width = 0;
	param->name = NULL;
	param->map = NULL;
	ft_sdl_initial(param);
	return(param);
}