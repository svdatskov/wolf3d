/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_sides.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:49:35 by sdatskov          #+#    #+#             */
/*   Updated: 2019/07/18 21:49:37 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_sides2(t_param *p)
{
	p->img = p->image[4]->pixels;
	if (((PR->ray_x < 0 && PR->ray_y < 0) ||
	(PR->ray_x >= 0 && PR->ray_y < 0)) && PR->side == 1)
		p->img = p->image[5]->pixels;
	if (((PR->ray_x < 0 && PR->ray_y >= 0) ||
	(PR->ray_x >= 0 && PR->ray_y >= 0)) && PR->side == 1)
		p->img = p->image[6]->pixels;
	if (((PR->ray_x >= 0 && PR->ray_y < 0) ||
	(PR->ray_x >= 0 && PR->ray_y >= 0)) && PR->side == 0)
		p->img = p->image[7]->pixels;
}

void		ft_sides(t_param *p)
{
	if (p->flags.textures == -1)
	{
		p->img = p->image[0]->pixels;
		if (((PR->ray_x < 0 && PR->ray_y < 0) ||
		(PR->ray_x >= 0 && PR->ray_y < 0)) && PR->side == 1)
			p->img = p->image[1]->pixels;
		if (((PR->ray_x < 0 && PR->ray_y >= 0) ||
		(PR->ray_x >= 0 && PR->ray_y >= 0)) && PR->side == 1)
			p->img = p->image[2]->pixels;
		if (((PR->ray_x >= 0 && PR->ray_y < 0) ||
		(PR->ray_x >= 0 && PR->ray_y >= 0)) && PR->side == 0)
			p->img = p->image[3]->pixels;
	}
	else if (p->flags.textures == 1)
	{
		ft_sides2(p);
	}
}
