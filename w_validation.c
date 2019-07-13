#include "wolf3d.h"

static t_param *first_stage(int fd, t_param *param)
{
	int player;

	player = 0;
	while (get_next_line(fd, &param->line) == 1)
	{
		param->width = 0;
		while (param->line[param->width]) {
			param->width++;
			if (param->line[param->width] == 'x')
				player++;
		}
		if (param->height == 0)
			param->base_width = param->width;
		else if (param->width != param->base_width)
			ft_error(3);
		param->height++;
	}
	if (player != 1)
		ft_error(3);
	close(fd);
	return (param);
}

static void second_stage(int fd, t_param *param)
{
	int width;
	int height;

	width = 0;
	height = 0;
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
	}
//	free(param->line);
	close(fd);
}

void	ft_validation(t_param *param)
{
	int fd;
	if ((fd = open(param->name, O_RDONLY)) < 1)
		ft_error(2);
	param->width = 0;
	param->height = 0;
	param->base_width = 0;
	param = first_stage(fd, param);
	fd = open(param->name, O_RDONLY);
	second_stage(fd, param);
}
