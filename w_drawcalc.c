#include "wolf3d.h"

t_textur	draw_texture(t_param *p)
{
	t_textur t;

	if (p->pr->side == 0)
		t.text_wall = p->pr->p_y + p->pr->pwd * p->pr->ray_y;
	else
		t.text_wall = p->pr->p_x + p->pr->pwd * p->pr->ray_x;
	t.text_wall -= (int)((t.text_wall));
		t.text_x = (int)(t.text_wall * (double)(T_WIDTH));
	if(p->pr->side == 0 && p->pr->ray_x > 0)
		t.text_x = T_WIDTH - t.text_x - 1;
	if(p->pr->side == 1 && p->pr->ray_y < 0)
		t.text_x = T_WIDTH - t.text_x - 1;
	return (t);
}

t_textur	draw_wall(t_param *p, t_textur t, int y, int x)
{
	t.b = y * 256 - HEIGHT * 128 + p->pr->line_h * 128;
	t.text_y = ((t.b * T_HEIGHT) / p->pr->line_h) / 256;
	t.color = p->img[T_HEIGHT * t.text_y + t.text_x];
	p->data_img[y * WIDTH + x] = t.color;
	return (t);
}