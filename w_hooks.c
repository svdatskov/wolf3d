#include "wolf3d.h"
#include <stdio.h>
//static t_time ft_frametime(t_param *param)
//{
//	param->time.old_time = param->time.time;
//	param->time.time = SDL_GetTicks();
//	param->time.frame_time = (param->time.time - param->time.old_time) / 1000.0;
//	param->time.move_speed = param->time.frame_time * 5.0;
//	param->time.rot_speed = param->time.frame_time * 3.0;
//	return (param->time);
//}

t_time	ft_hooks(t_param *param)
{
	if ((param->event.type == SDL_QUIT) ||
		(param->event.type == SDL_KEYDOWN && param->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
		param->running = 0;
	//param->time = ft_frametime(param);
	if (param->event.type == SDL_KEYDOWN && param->event.key.keysym.sym == SDLK_UP)
	{
		if (param->map[(int)(param->print->posY)][(int)(param->print->posX + param->print->dirX * param->time.move_speed)] == '0')
			param->print->posX += param->print->dirX * param->time.move_speed;
		if(param->map[(int)(param->print->posY + param->print->dirY * param->time.move_speed)][	(int)(param->print->posX)] == '0')
			param->print->posY += param->print->dirY * param->time.move_speed;

	}
	if (param->event.type == SDL_KEYDOWN && param->event.key.keysym.sym == SDLK_DOWN)
	{
		if (param->map[(int)(param->print->posY)][(int)(param->print->posX + param->print->dirX * param->time.move_speed)] == '0')
			param->print->posX -= param->print->dirX * param->time.move_speed;
		if(param->map[(int)(param->print->posY + param->print->dirY * param->time.move_speed)][	(int)(param->print->posX)] == '0')
			param->print->posY -= param->print->dirY * param->time.move_speed;
	}
	if (param->event.type == SDL_KEYDOWN && param->event.key.keysym.sym == SDLK_LEFT)
	{
//		param->print->olddirX = param->print->dirX;
//		param->print->dirX = param->print->dirX * cos(param->time.rot_speed) - param->print->dirY * sin(param->time.rot_speed);
//		param->print->dirY = param->print->olddirX * sin(param->time.rot_speed) + param->print->dirY * cos(param->time.rot_speed);
//		param->print->dirY = param->print->dirX * cos(param->time.rot_speed) - param->print->dirY * sin(param->time.rot_speed);
//		param->print->oldplaneX = param->print->planeX;
//		param->print->planeX = param->print->planeX * cos(param->time.rot_speed) - param->print->planeY * sin(param->time.rot_speed);
//		param->print->planeY = param->print->oldplaneX * sin(param->time.rot_speed) + param->print->planeY * cos(param->time.rot_speed);
//		printf("%f\n %f\n", param->print->planeX, param->print->planeY);
//		printf("%f\n %f\n", param->print->dirX, param->print->dirY);
		param->print->olddirX = param->print->dirX;
		param->print->dirX = param->print->dirX * cos(param->time.rot_speed) - param->print->dirY * sin(param->time.rot_speed);
		param->print->dirY = param->print->olddirX * sin(param->time.rot_speed) + param->print->dirY * cos(param->time.rot_speed);
		param->print->oldplaneX = param->print->planeX;
		param->print->planeX = param->print->planeX * cos(param->time.rot_speed) - param->print->planeY * sin(param->time.rot_speed);
		param->print->planeY = param->print->oldplaneX * sin(param->time.rot_speed) + param->print->planeY * cos(param->time.rot_speed);

	}
	if (param->event.type == SDL_KEYDOWN && param->event.key.keysym.sym == SDLK_RIGHT)
	{
		param->print->olddirX = param->print->dirX;
		param->print->dirX = param->print->dirX * cos(-param->time.rot_speed) - param->print->dirY * sin(-param->time.rot_speed);
		param->print->dirY = param->print->olddirX * sin(-param->time.rot_speed) + param->print->dirY * cos(-param->time.rot_speed);
		param->print->dirY = param->print->dirX * cos(-param->time.rot_speed) - param->print->dirY * sin(-param->time.rot_speed);
		param->print->oldplaneX = param->print->planeX;
		param->print->planeX = param->print->planeX * cos(-param->time.rot_speed) - param->print->planeY * sin(-param->time.rot_speed);
		param->print->planeY = param->print->oldplaneX * sin(-param->time.rot_speed) + param->print->planeY * cos(-param->time.rot_speed);
		printf("%f\n %f\n", param->print->planeX, param->print->planeY);
		printf("%f\n %f\n", param->print->dirX, param->print->dirY);

	}
	return (param->time);
}