#include "wolf3d.h"

static void ft_main_initial(t_param *param)
{
    param->height = 0;
    param->width = 0;
    param->base_width = 0;
    param->name = NULL;
    param->map = NULL;
    param->running = 1;
    param->flags.right = 0;
	param->flags.left = 0;
	param->flags.up = 0;
	param->flags.down = 0;
	param->flags.speed = 0;
}

static void ft_print_initial(t_param *param)
{
    if(!(param->pr = (t_print *)malloc(sizeof(t_print))))
        ft_error(4);
    param->pr->d_x = -1;
    param->pr->d_y = 0;
    param->pr->pl_x = 0;
    param->pr->pl_y = 0.66;
}

static void ft_time_initial(t_param *param)
{
    param->time.old_time = param->time.time;
    param->time.time = SDL_GetTicks();
    param->time.fr_t = (param->time.time - param->time.old_time) / 1000.0;
    param->time.mv_s = param->time.fr_t * 5.0;
    param->time.ro_s = param->time.fr_t * 3.0;
}

static void	ft_sdl_initial(t_param *param)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	param->window = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	if (param->window == NULL)
		exit (5);
	param->image = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * 8);
	param->surface = SDL_GetWindowSurface(param->window);
	param->data_img = param->surface->pixels;
	param->image[0] = IMG_Load("../pics/eagle.png");
	param->image[1] = IMG_Load("../pics/redbrick.png");
	param->image[2] = IMG_Load("../pics/purplestone.png");
	param->image[3] = IMG_Load("../pics/greystone.png");
	param->image[4] = IMG_Load("../pics/bluestone.png");
	param->image[5] = IMG_Load("../pics/mossy.png");
	param->image[6] = IMG_Load("../pics/wood.png");
	param->image[7] = IMG_Load("../pics/colorstone.png");
	param->img = param->image[1]->pixels;
}

t_param 	*ft_initial(void)
{
	t_param *param;
    if (!(param = (t_param*)malloc(sizeof(t_param))))
        ft_error(4);
	ft_main_initial(param);
	ft_print_initial(param);
	ft_time_initial(param);
	ft_sdl_initial(param);
	return(param);
}