#include "wolf3d.h"

void ft_error(int error)
{
	if (error == 1)
	{
		ft_putendl("Usage: ./wolf3d [map]");
		exit(1);
	}
	if (error == 2)
	{
		ft_putendl("Wrong MAP File!");
		exit(2);
	}
	if (error == 3)
	{
		ft_putendl("Validation ERROR!");
		exit(3);
	}
}
