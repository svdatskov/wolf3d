#include "wolf3d.h"


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
			param->time.old_time = param->time.time;
			param->time.time = SDL_GetTicks();
			param->time.fr_t = (param->time.time - param->time.old_time) / 1000.0;
			param->time.mv_s = param->time.fr_t * 7.0;
			param->time.ro_s = param->time.fr_t * 3.0;
			if (param->event.type == SDL_KEYDOWN) {
				param->time = ft_hooks(param);
				param->event.key.keysym.sym = 0;
			}
		}
	}
	else
		ft_error(1);
	system("leaks -q wolf3d");
	return (0);
}