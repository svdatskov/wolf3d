#include "wolf3d.h"

static void ft_exit(t_param *param)
{
    if ((param->event.type == SDL_QUIT) ||
        (param->event.type == SDL_KEYDOWN && param->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
        param->running = 0;
}

static void ft_recalculate(t_param *param)
{
    param->time.old_time = param->time.time;
    param->time.time = SDL_GetTicks();
    param->time.fr_t = (param->time.time - param->time.old_time) / 1000.0;
    param->time.mv_s = param->time.fr_t * 20.0;
    param->time.ro_s = param->time.fr_t * 3.0;
}


int main(int argc, char **argv)
{
	t_param *param;
	if (argc == 2)
	{
		param = ft_initial();
		param->name = argv[1];
		ft_validation(param);
		ft_readmap(param);
		while (param->running)
		{
			ft_printmap(param);
			ft_recalculate(param);
			if (param->event.type == SDL_KEYDOWN) {
				param->time = ft_hooks(param);
				param->event.key.keysym.sym = 0;
			}
			ft_exit(param);
		}
		printf("%i\n %i\n", param->width, param->height);
	}
	else
		ft_error(1);
	return (0);
}