#include "wolf3d.h"

t_time	ft_hooks(t_param *param)
{
	if (param->flags.up)
	{
		if (param->map[(int)(param->pr->p_y)][(int)(param->pr->p_x + param->pr->d_x * param->time.mv_s)] == '0' ||
		param->map[(int)(param->pr->p_y)][(int)(param->pr->p_x + param->pr->d_x * param->time.mv_s)] == 'x')
			param->pr->p_x += param->pr->d_x * param->time.mv_s;
		if(param->map[(int)(param->pr->p_y + param->pr->d_y * param->time.mv_s)][(int)(param->pr->p_x)] == '0' ||
		param->map[(int)(param->pr->p_y + param->pr->d_y * param->time.mv_s)][(int)(param->pr->p_x)] == 'x')
			param->pr->p_y += param->pr->d_y * param->time.mv_s;
	}
	if (param->flags.down)
	{
		if (param->map[(int)(param->pr->p_y)][(int)(param->pr->p_x - param->pr->d_x * param->time.mv_s)] == '0' ||
				param->map[(int)(param->pr->p_y)][(int)(param->pr->p_x - param->pr->d_x * param->time.mv_s)] == 'x')
			param->pr->p_x -= param->pr->d_x * param->time.mv_s;
		if(param->map[(int)(param->pr->p_y - param->pr->d_y * param->time.mv_s)][(int)(param->pr->p_x)] == '0'||
		param->map[(int)(param->pr->p_y - param->pr->d_y * param->time.mv_s)][(int)(param->pr->p_x)] == 'x')
			param->pr->p_y -= param->pr->d_y * param->time.mv_s;
	}
	if (param->flags.right)
	{
		param->pr->od_X = param->pr->d_x;
		param->pr->d_x = param->pr->d_x * cos(param->time.ro_s) - param->pr->d_y * sin(param->time.ro_s);
		param->pr->d_y = param->pr->od_X * sin(param->time.ro_s) + param->pr->d_y * cos(param->time.ro_s);
		param->pr->opl_x = param->pr->pl_x;
		param->pr->pl_x = param->pr->pl_x * cos(param->time.ro_s) - param->pr->pl_y * sin(param->time.ro_s);
		param->pr->pl_y = param->pr->opl_x * sin(param->time.ro_s) + param->pr->pl_y * cos(param->time.ro_s);
	}
	if (param->flags.left)
	{
		param->pr->od_X = param->pr->d_x;
		param->pr->d_x = param->pr->d_x * cos(-param->time.ro_s) - param->pr->d_y * sin(-param->time.ro_s);
		param->pr->d_y = param->pr->od_X * sin(-param->time.ro_s) + param->pr->d_y * cos(-param->time.ro_s);
		param->pr->opl_x = param->pr->pl_x;
		param->pr->pl_x = param->pr->pl_x * cos(-param->time.ro_s) - param->pr->pl_y * sin(-param->time.ro_s);
		param->pr->pl_y = param->pr->opl_x * sin(-param->time.ro_s) + param->pr->pl_y * cos(-param->time.ro_s);
	}
	return (param->time);
}