#include "wolf3d.h"

t_param 	*ft_initial(void)
{
	t_param *param;
	if (!(param = (t_param*)malloc(sizeof(t_param))))
		ft_error(4);
	param->height = 0;
	param->width = 0;
	param->base_width = 0;
	param->name = NULL;
	param->map = NULL;
	return(param);
}