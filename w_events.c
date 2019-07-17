#include "wolf3d.h"

t_param		*ft_events(t_param *param)
{
	while(SDL_PollEvent(&param->event)) {
		if (param->event.type == SDL_KEYDOWN && param->event.key.keysym.sym == SDLK_UP)
			param->flags.up = 1;
		else if (param->event.type == SDL_KEYUP && param->event.key.keysym.sym == SDLK_UP)
			param->flags.up = 0;
		else if (param->event.type == SDL_KEYDOWN && param->event.key.keysym.sym == SDLK_DOWN)
			param->flags.down = 1;
		else if (param->event.type == SDL_KEYUP && param->event.key.keysym.sym == SDLK_DOWN)
			param->flags.down = 0;
		else if (param->event.type == SDL_KEYDOWN && param->event.key.keysym.sym == SDLK_LEFT)
			param->flags.left = 1;
		else if (param->event.type == SDL_KEYUP && param->event.key.keysym.sym == SDLK_LEFT)
			param->flags.left = 0;
		else if (param->event.type == SDL_KEYDOWN && param->event.key.keysym.sym == SDLK_RIGHT)
			param->flags.right = 1;
		else if (param->event.type == SDL_KEYUP && param->event.key.keysym.sym == SDLK_RIGHT)
			param->flags.right = 0;
		else if (param->event.type == SDL_KEYDOWN && param->event.key.keysym.sym == SDLK_LSHIFT)
			param->flags.speed = 1;
		else if (param->event.type == SDL_KEYUP && param->event.key.keysym.sym == SDLK_LSHIFT)
			param->flags.speed = 0;
	}
	return (param);
}