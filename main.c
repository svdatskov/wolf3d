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
//		SDL_SetRenderDrawColor(param->render, 0, 0, 0, 0);
//		SDL_RenderClear(param->render);

		while (param->running)
		{
			ft_printmap(param);
//			SDL_RenderPresent(param->render);
//			SDL_SetRenderDrawColor(param->render, 0, 0, 0, 0);
//			SDL_RenderClear(param->render);
			param->time.old_time = param->time.time;
			param->time.time = SDL_GetTicks();
			param->time.frame_time = (param->time.time - param->time.old_time) / 1000.0;
			param->time.move_speed = param->time.frame_time * 7.0;
			param->time.rot_speed = param->time.frame_time * 3.0;
			if (param->event.type == SDL_KEYDOWN) {
				param->time = ft_hooks(param);
				param->event.key.keysym.sym = 0;
			}
		}
	}
	else
		ft_error(1);
	return (0);
}