#include "wolf3d.h"

static t_param *first_stage(int fd, t_param *param)
{
	int player;

	player = 0;
	while (get_next_line(fd, &param->line) == 1)
	{
		param->width = 0;
		while (param->line[param->width]) {
			if (param->line[param->width] == 'x') {
				player++;
				param->pr->p_x = param->width;
				param->pr->p_y = param->height;
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

static void second_stage(int fd, t_param *param, int width, int height)
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
			else {
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

void	ft_validation(t_param *param)
{
	int fd;
	int width;
	int height;
	char **str;

	width = 0;
	height = 0;
	str = ft_strsplit(param->name, '.');
	if (str[1] == NULL)
		ft_error(1);
	else {
		if (ft_strcmp(str[1], "wolf") != 0)
			ft_error(1);
	}
	if ((fd = open(param->name, O_RDONLY)) < 1)
		ft_error(2);
	param->width = 0;
	param->height = 0;
	param->base_width = 0;
	param = first_stage(fd, param);
	fd = open(param->name, O_RDONLY);
	second_stage(fd, param, width, height);
}
