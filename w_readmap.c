/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_readmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:39:32 by sdatskov          #+#    #+#             */
/*   Updated: 2019/07/18 21:39:34 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_readmap(t_param *param)
{
	int fd;
	int cnt;

	cnt = 0;
	if (!(param->map = (char **)malloc(sizeof(char *) * param->height)))
		ft_error(4);
	fd = open(param->name, O_RDONLY);
	while (get_next_line(fd, &param->line) == 1)
	{
		param->map[cnt] = (char *)malloc(sizeof(char) * (param->width + 1));
		ft_strcpy(param->map[cnt], param->line);
		free(param->line);
		cnt++;
	}
}
