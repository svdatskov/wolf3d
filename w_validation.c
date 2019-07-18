/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_validation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 22:04:39 by sdatskov          #+#    #+#             */
/*   Updated: 2019/07/18 22:04:40 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_param	*first_stage_plus(t_param *param, int player, int fd)
{
	while (get_next_line(fd, &param->line) == 1)
	{
		param->width = 0;
		while (param->line[param->width])
		{
			if (param->line[param->width] == 'x')
			{
				player++;
				param->pr->p_x = param->width + 0.5;
				param->pr->p_y = param->height + 0.5;
			}
			param->width++;
		}
		if (param->height == 0)
			param->base_width = param->width;
		else if (param->width != param->base_width)
			ft_error(3);
		param->height++;
		free(param->line);
	}
	if (player != 1)
		ft_error(3);
	close(fd);
	return (param);
}

static t_param	*first_stage(int fd, t_param *param)
{
	int player;

	player = 0;
	return (first_stage_plus(param, player, fd));
}

static void		second_stage(int fd, t_param *param, int width, int height)
{
	while (get_next_line(fd, &param->line) == 1)
	{
		while (param->line[width])
		{
			if (height == 0 || height == param->height - 1
			|| width == 0 || width == param->width - 1)
			{
				if (param->line[width] != '1')
					ft_error(3);
			}
			else
			{
				if (param->line[width] != '1' && param->line[width] != '0'
				&& param->line[width] != 'x')
					ft_error(3);
			}
			width++;
		}
		height++;
		width = 0;
		free(param->line);
	}
	close(fd);
}

static void		ft_check_name(char *name)
{
	char	**str;
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	str = ft_strsplit(name, '.');
	while (str[i])
		i++;
	if (str[i - 1] == NULL)
		ft_error(1);
	else
	{
		if (ft_strcmp(str[i - 1], "wolf") != 0)
			ft_error(1);
	}
	while (cnt < i)
		free(str[cnt++]);
	free(str);
}

void			ft_validation(t_param *param)
{
	int		fd;
	int		width;
	int		height;

	width = 0;
	height = 0;
	ft_check_name(param->name);
	if ((fd = open(param->name, O_RDONLY)) < 1)
		ft_error(2);
	param->width = 0;
	param->height = 0;
	param->base_width = 0;
	param = first_stage(fd, param);
	fd = open(param->name, O_RDONLY);
	second_stage(fd, param, width, height);
}
