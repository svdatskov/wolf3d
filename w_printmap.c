#include "wolf3d.h"

static void verLine(int x, int drawStart, int drawEnd, int color, t_param *param)
{
	int y = 0;
	while (y < drawStart)
	{
		param->data_img[y * WIDTH + x] = 0;
		y++;
	}
	y = drawStart;
	while (y <= drawEnd)
	{
		param->data_img[y * WIDTH + x] = color;
		y++;
	}
	y = drawEnd + 1;
	while (y < HEIGHT)
	{
		param->data_img[y * WIDTH + x] = 0;
		y++;
	}
}


void	ft_printmap(t_param *param)
{
	int x = 0;
		while(SDL_PollEvent(&param->event)) {
			if ((param->event.type == SDL_QUIT) ||
				(param->event.type == SDL_KEYDOWN && param->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
				param->running = 0;
			while (x < (double)WIDTH) {
				param->print->cameraX = 1 - 2.0 * x / (double) WIDTH;
				param->print->rayDirX = param->print->dirX + param->print->planeX * param->print->cameraX;
				param->print->rayDirY = param->print->dirY + param->print->planeY * param->print->cameraX;
				param->print->mapX = (int)param->print->posX;
				param->print->mapY = (int)param->print->posY;
				param->print->deltaDistX = fabs(1 / param->print->rayDirX);
				param->print->deltaDistY = fabs(1 / param->print->rayDirY);
				param->print->hit = 0;
				if (param->print->rayDirX < 0) {
					param->print->stepX = -1;
					param->print->sideDistX = (param->print->posX - param->print->mapX) * param->print->deltaDistX;
				} else {
					param->print->stepX = 1;
					param->print->sideDistX = (param->print->mapX + 1.0 - param->print->posX) * param->print->deltaDistX;
				}
				if (param->print->rayDirY < 0) {
					param->print->stepY = -1;
					param->print->sideDistY = (param->print->posY - param->print->mapY) * param->print->deltaDistY;
				} else {
					param->print->stepY = 1;
					param->print->sideDistY = (param->print->mapY + 1.0 - param->print->posY) * param->print->deltaDistY;
				}
				while (param->print->hit == 0) {
					if (param->print->sideDistX < param->print->sideDistY) {
						param->print->sideDistX += param->print->deltaDistX;
						param->print->mapX += param->print->stepX;
						param->print->side = 0;
					} else {
						param->print->sideDistY += param->print->deltaDistY;
						param->print->mapY += param->print->stepY;
						param->print->side = 1;
					}
					if (param->map[param->print->mapY][param->print->mapX] == '1')
						param->print->hit = 1;
				}
				if (param->print->side == 0)
					param->print->perpWallDist = (param->print->mapX - param-> print->posX + (1 - param->print->stepX) / 2) / param->print->rayDirX;
				else
					param->print->perpWallDist = (param->print->mapY - param->print->posY + (1 - param->print->stepY) / 2) / param->print->rayDirY;

				param->print->lineHeight = (int) (HEIGHT / param->print->perpWallDist);

				param->print->drawStart = -param->print->lineHeight / 2 + HEIGHT / 2;
				if (param->print->drawStart < 0)
					param->print->drawStart = 0;
				param->print->drawEnd = param->print->lineHeight / 2 + HEIGHT / 2;
				if (param->print->drawEnd >= HEIGHT)
					param->print->drawEnd = HEIGHT - 1;
				int color = 0x00FF00;
//				switch(param->map[mapX][mapY])
//				{
//					case 1:  color = 0xff0000;  break; //red
//					case 2:  color = 0x00ff00;  break; //green
//					case 3:  color = 0x0000ff;   break; //blue
//					case 4:  color = 0xffffff;  break; //white
//					default: color = 0xff8000; break; //yellow
//				}

				if (param->print->side == 1) { color = color / 2; }

				verLine(x, param->print->drawStart, param->print->drawEnd, color, param);
				x++;
			}
	SDL_UpdateWindowSurface(param->window);
		}
}