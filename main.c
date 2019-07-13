#include "wolf3d.h"


int main(int argc, char **argv)
{
	t_param *param;
	if (argc == 2)
	{
		param = ft_initial();
		param->name = argv[1];
		ft_validation(param);
		ft_readmap(param);
	}
	else
		ft_error(1);
	return (0);
}