#include "wolf3d.h"


int main(int argc, char **argv)
{
	t_param param;
	if (argc == 2)
	{
		param.name = argv[1];;
		param = ft_validation(param);

	}
	else
		ft_error(1);
	return (0);
}