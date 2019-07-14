#include "wolf3d.h"

void ft_readmap(t_param *param)
{
	int fd;
	int cnt;
	int i;

	cnt = 0;
	i = 0;
	if (!(param->map = (char **)malloc(sizeof(char *) * param->height)))
		ft_error(4);
	fd = open(param->name, O_RDONLY);
	while (get_next_line(fd, &param->line) == 1)
	{
		param->map[cnt] = (char *)malloc(sizeof(char) * (param->width + 1));
		while (i <= param->width)
        {
		    param->map[cnt][i] = param->line[i];
		    i++;
        }
		i = 0;
		cnt++;
	}
}
