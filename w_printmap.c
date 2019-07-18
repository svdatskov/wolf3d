/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_printmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:38:56 by sdatskov          #+#    #+#             */
/*   Updated: 2019/07/18 21:38:58 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_line(int x, int dr_s, int dr_e, t_param *param)
{
	t_textur	t;
	int			y;

	ft_sides(param);
	t = draw_texture(param);
	y = 0;
	while (y < dr_s)
	{
		param->data_img[y * WIDTH + x] = 0xe5e5ff;
		y++;
	}
	y = dr_s;
	while (y < dr_e)
	{
		t = draw_wall(param, t, y, x);
		y++;
	}
	y = dr_e + 1;
	while (y < HEIGHT)
	{
		param->data_img[y * WIDTH + x] = 0x696969;
		y++;
	}
}

static void	conditions(t_param *p)
{
	if (p->pr->ray_x < 0)
	{
		p->pr->st_x = -1;
		p->pr->sd_x = (p->pr->p_x - p->pr->map_y) * p->pr->dlt_x;
	}
	else
	{
		p->pr->st_x = 1;
		p->pr->sd_x = (p->pr->map_y + 1.0 - p->pr->p_x) * p->pr->dlt_x;
	}
	if (p->pr->ray_y < 0)
	{
		p->pr->st_y = -1;
		p->pr->sd_y = (p->pr->p_y - p->pr->map_x) * p->pr->dlt_y;
	}
	else
	{
		p->pr->st_y = 1;
		p->pr->sd_y = (p->pr->map_x + 1.0 - p->pr->p_y) * p->pr->dlt_y;
	}
}

static void	conditions2(t_param *p)
{
	while (p->pr->hit == 0)
	{
		if (p->pr->sd_x < p->pr->sd_y)
		{
			p->pr->sd_x += p->pr->dlt_x;
			p->pr->map_y += p->pr->st_x;
			p->pr->side = 0;
		}
		else
		{
			p->pr->sd_y += p->pr->dlt_y;
			p->pr->map_x += p->pr->st_y;
			p->pr->side = 1;
		}
		if (p->map[p->pr->map_x][p->pr->map_y] == '1')
			p->pr->hit = 1;
	}
	if (p->pr->side == 0)
		p->pr->pwd = (p->pr->map_y - p->pr->p_x + (1 - p->pr->st_x) / 2)
				/ p->pr->ray_x;
	else
		p->pr->pwd = (p->pr->map_x - p->pr->p_y + (1 - p->pr->st_y) / 2)
				/ p->pr->ray_y;
	p->pr->line_h = (int)(HEIGHT / p->pr->pwd);
	p->pr->dr_s = -p->pr->line_h / 2 + HEIGHT / 2;
}

static void	conditions3(t_param *p, int x)
{
	p->pr->cam_x = 1 - 2.0 * x / (double)WIDTH;
	p->pr->ray_x = p->pr->d_x + p->pr->pl_x * p->pr->cam_x;
	p->pr->ray_y = p->pr->d_y + p->pr->pl_y * p->pr->cam_x;
	p->pr->map_y = (int)p->pr->p_x;
	p->pr->map_x = (int)p->pr->p_y;
	p->pr->dlt_x = fabs(1 / p->pr->ray_x);
	p->pr->dlt_y = fabs(1 / p->pr->ray_y);
	p->pr->hit = 0;
}

void		ft_printmap(t_param *p)
{
	int x;

	x = 0;
	while (x < (double)WIDTH)
	{
		conditions3(p, x);
		conditions(p);
		conditions2(p);
		if (p->pr->dr_s < 0)
			p->pr->dr_s = 0;
		p->pr->dr_e = p->pr->line_h / 2 + HEIGHT / 2;
		if (p->pr->dr_e >= HEIGHT)
			p->pr->dr_e = HEIGHT - 1;
		draw_line(x, p->pr->dr_s, p->pr->dr_e, p);
		x++;
	}
	SDL_UpdateWindowSurface(p->window);
}
