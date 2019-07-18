/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:12:10 by sdatskov          #+#    #+#             */
/*   Updated: 2019/07/18 20:12:12 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	hook_up(t_param *p)
{
	if (p->map[(int)(PR->p_y)][(int)(PR->p_x + PR->d_x * TM.mv_s)] == '0' ||
		p->map[(int)(PR->p_y)][(int)(PR->p_x + PR->d_x * TM.mv_s)] == 'x')
		PR->p_x += PR->d_x * p->time.mv_s;
	if (p->map[(int)(PR->p_y + PR->d_y * TM.mv_s)][(int)(PR->p_x)] == '0' ||
		p->map[(int)(PR->p_y + PR->d_y * TM.mv_s)][(int)(PR->p_x)] == 'x')
		PR->p_y += PR->d_y * TM.mv_s;
}

static void	hook_down(t_param *p)
{
	if (p->map[(int)(PR->p_y)][(int)(PR->p_x - PR->d_x * TM.mv_s)] == '0' ||
		p->map[(int)(PR->p_y)][(int)(PR->p_x - PR->d_x * TM.mv_s)] == 'x')
		PR->p_x -= PR->d_x * p->time.mv_s;
	if (p->map[(int)(PR->p_y - PR->d_y * TM.mv_s)][(int)(PR->p_x)] == '0' ||
		p->map[(int)(PR->p_y - PR->d_y * TM.mv_s)][(int)(PR->p_x)] == 'x')
		PR->p_y -= PR->d_y * TM.mv_s;
}

static void	hook_right(t_param *p)
{
	PR->od_x = PR->d_x;
	PR->d_x = PR->d_x * cos(TM.ro_s) - PR->d_y * sin(TM.ro_s);
	PR->d_y = PR->od_x * sin(TM.ro_s) + PR->d_y * cos(TM.ro_s);
	PR->opl_x = PR->pl_x;
	PR->pl_x = PR->pl_x * cos(TM.ro_s) - PR->pl_y * sin(TM.ro_s);
	PR->pl_y = PR->opl_x * sin(TM.ro_s) + PR->pl_y * cos(TM.ro_s);
}

static void	hook_left(t_param *p)
{
	PR->od_x = PR->d_x;
	PR->d_x = PR->d_x * cos(-TM.ro_s) - PR->d_y * sin(-TM.ro_s);
	PR->d_y = PR->od_x * sin(-TM.ro_s) + PR->d_y * cos(-TM.ro_s);
	PR->opl_x = PR->pl_x;
	PR->pl_x = PR->pl_x * cos(-TM.ro_s) - PR->pl_y * sin(-TM.ro_s);
	PR->pl_y = PR->opl_x * sin(-TM.ro_s) + PR->pl_y * cos(-TM.ro_s);
}

t_time		ft_hooks(t_param *p)
{
	if (p->flags.up)
		hook_up(p);
	if (p->flags.down)
		hook_down(p);
	if (p->flags.right)
		hook_right(p);
	if (p->flags.left)
		hook_left(p);
	return (p->time);
}
