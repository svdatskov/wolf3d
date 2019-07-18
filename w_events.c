/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_events.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:49:26 by sdatskov          #+#    #+#             */
/*   Updated: 2019/07/18 19:49:28 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_buttons(t_param *p)
{
	if (KEYDOWN && p->event.key.keysym.sym == SDLK_UP)
		p->flags.up = 1;
	else if (KEYUP && p->event.key.keysym.sym == SDLK_UP)
		p->flags.up = 0;
	else if (KEYDOWN && p->event.key.keysym.sym == SDLK_DOWN)
		p->flags.down = 1;
	else if (KEYUP && p->event.key.keysym.sym == SDLK_DOWN)
		p->flags.down = 0;
	else if (KEYDOWN && p->event.key.keysym.sym == SDLK_LEFT)
		p->flags.left = 1;
	else if (KEYUP && p->event.key.keysym.sym == SDLK_LEFT)
		p->flags.left = 0;
	else if (KEYDOWN && p->event.key.keysym.sym == SDLK_RIGHT)
		p->flags.right = 1;
	else if (KEYUP && p->event.key.keysym.sym == SDLK_RIGHT)
		p->flags.right = 0;
	else if (KEYDOWN && p->event.key.keysym.sym == SDLK_LSHIFT)
		p->flags.speed = 1;
	else if (KEYUP && p->event.key.keysym.sym == SDLK_LSHIFT)
		p->flags.speed = 0;
	else if (KEYUP && p->event.key.keysym.sym == SDLK_SPACE)
		p->flags.textures = p->flags.textures * -1;
}

t_param		*ft_events(t_param *p)
{
	while (SDL_PollEvent(&p->event))
		ft_buttons(p);
	return (p);
}
