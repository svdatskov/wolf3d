#include "wolf3d.h"

static void verLine(int x, int dr_s, int dr_e, int color, t_param *param)
{
	int y = 0;
	while (y < dr_s)
	{
		param->data_img[y * WIDTH + x] = 0;
		y++;
	}
	y = dr_s;
	while (y <= dr_e)
	{
		param->data_img[y * WIDTH + x] = color;
		y++;
	}
	y = dr_e + 1;
	while (y < HEIGHT)
	{
		param->data_img[y * WIDTH + x] = 0;
		y++;
	}
}

static void conditions(t_param *p)
{
    if (p->pr->ray_x < 0)
    {
        p->pr->st_x = -1;
        p->pr->sd_x = (p->pr->p_x - p->pr->mapX) * p->pr->dlt_x;
    }
    else
    {
        p->pr->st_x = 1;
        p->pr->sd_x = (p->pr->mapX + 1.0 - p->pr->p_x) * p->pr->dlt_x;
    }
    if (p->pr->ray_y < 0)
    {
        p->pr->st_y = -1;
        p->pr->sd_y = (p->pr->p_y - p->pr->mapY) * p->pr->dlt_y;
    }
    else
    {
        p->pr->st_y = 1;
        p->pr->sd_y = (p->pr->mapY + 1.0 - p->pr->p_y) * p->pr->dlt_y;
    }
}

static void conditions2(t_param *p)
{
    while (p->pr->hit == 0)
    {
        if (p->pr->sd_x < p->pr->sd_y)
        {
            p->pr->sd_x += p->pr->dlt_x;
            p->pr->mapX += p->pr->st_x;
            p->pr->side = 0;
        }
        else
        {
            p->pr->sd_y += p->pr->dlt_y;
            p->pr->mapY += p->pr->st_y;
            p->pr->side = 1;
        }
        if (p->map[p->pr->mapY][p->pr->mapX] == '1')
            p->pr->hit = 1;
    }
    if (p->pr->side == 0)
        p->pr->pwd = (p->pr->mapX - p-> pr->p_x + (1 - p->pr->st_x) / 2) / p->pr->ray_x;
    else
        p->pr->pwd = (p->pr->mapY - p->pr->p_y + (1 - p->pr->st_y) / 2) / p->pr->ray_y;
    p->pr->lineHeight = (int) (HEIGHT / p->pr->pwd);
    p->pr->drS = -p->pr->lineHeight / 2 + HEIGHT / 2;
}

static void conditions3(t_param *p, int x)
{
    p->pr->cam_x = 1 - 2.0 * x / (double) WIDTH;
    p->pr->ray_x = p->pr->d_x + p->pr->pl_x * p->pr->cam_x;
    p->pr->ray_y = p->pr->d_y + p->pr->pl_y * p->pr->cam_x;
    p->pr->mapX = (int)p->pr->p_x;
    p->pr->mapY = (int)p->pr->p_y;
    p->pr->dlt_x = fabs(1 / p->pr->ray_x);
    p->pr->dlt_y = fabs(1 / p->pr->ray_y);
    p->pr->hit = 0;
}

void	ft_printmap(t_param *p)
{
	int x = 0;
		while(SDL_PollEvent(&p->event)) {
			while (x < (double)WIDTH) {
				conditions3(p, x);
				conditions(p);
				conditions2(p);
				if (p->pr->drS < 0)
					p->pr->drS = 0;
				p->pr->drE = p->pr->lineHeight / 2 + HEIGHT / 2;
				if (p->pr->drE >= HEIGHT)
					p->pr->drE = HEIGHT - 1;
				int color = 0x00FF00;
//				switch(p->map[mapX][mapY])
//				{
//					case 1:  color = 0xff0000;  break; //red
//					case 2:  color = 0x00ff00;  break; //green
//					case 3:  color = 0x0000ff;   break; //blue
//					case 4:  color = 0xffffff;  break; //white
//					default: color = 0xff8000; break; //yellow
//				}
				if (p->pr->side == 1) { color = color / 2; }

				verLine(x, p->pr->drS, p->pr->drE, color, p);
				x++;
			}
	SDL_UpdateWindowSurface(p->window);
		}
}