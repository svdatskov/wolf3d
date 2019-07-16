#include "wolf3d.h"

t_time	ft_hooks(t_param *param)
{
	if (param->event.type == SDL_KEYDOWN && param->event.key.keysym.sym == SDLK_UP)
	{
		if (param->map[(int)(param->pr->p_y)][(int)(param->pr->p_x + param->pr->d_x * param->time.mv_s)] == '0')
			param->pr->p_x += param->pr->d_x * param->time.mv_s;
		if(param->map[(int)(param->pr->p_y + param->pr->d_y * param->time.mv_s)][	(int)(param->pr->p_x)] == '0')
			param->pr->p_y += param->pr->d_y * param->time.mv_s;

	}
	if (param->event.type == SDL_KEYDOWN && param->event.key.keysym.sym == SDLK_DOWN)
	{
		if (param->map[(int)(param->pr->p_y)][(int)(param->pr->p_x + param->pr->d_x * param->time.mv_s)] == '0')
			param->pr->p_x -= param->pr->d_x * param->time.mv_s;
		if(param->map[(int)(param->pr->p_y + param->pr->d_y * param->time.mv_s)][	(int)(param->pr->p_x)] == '0')
			param->pr->p_y -= param->pr->d_y * param->time.mv_s;
	}
	if (param->event.type == SDL_KEYDOWN && param->event.key.keysym.sym == SDLK_RIGHT)
	{
		param->pr->od_X = param->pr->d_x;
		param->pr->d_x = param->pr->d_x * cos(param->time.ro_s) - param->pr->d_y * sin(param->time.ro_s);
		param->pr->d_y = param->pr->od_X * sin(param->time.ro_s) + param->pr->d_y * cos(param->time.ro_s);
		param->pr->opl_x = param->pr->pl_x;
		param->pr->pl_x = param->pr->pl_x * cos(param->time.ro_s) - param->pr->pl_y * sin(param->time.ro_s);
		param->pr->pl_y = param->pr->opl_x * sin(param->time.ro_s) + param->pr->pl_y * cos(param->time.ro_s);

	}
	if (param->event.type == SDL_KEYDOWN && param->event.key.keysym.sym == SDLK_LEFT)
	{
		param->pr->od_X = param->pr->d_x;
		param->pr->d_x = param->pr->d_x * cos(-param->time.ro_s) - param->pr->d_y * sin(-param->time.ro_s);
		param->pr->d_y = param->pr->od_X * sin(-param->time.ro_s) + param->pr->d_y * cos(-param->time.ro_s);
		param->pr->opl_x = param->pr->pl_x;
		param->pr->pl_x = param->pr->pl_x * cos(-param->time.ro_s) - param->pr->pl_y * sin(-param->time.ro_s);
		param->pr->pl_y = param->pr->opl_x * sin(-param->time.ro_s) + param->pr->pl_y * cos(-param->time.ro_s);
		printf("%f\n %f\n", param->pr->pl_x, param->pr->pl_y);
		printf("%f\n %f\n", param->pr->d_x, param->pr->d_y);

	}
	return (param->time);
}