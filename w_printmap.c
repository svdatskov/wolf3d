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

static t_print set_param(void)
{
	t_print print;

	print.posX = 6;
	print.posY = 2.2;
	print.dirX = -1;
	print.dirY = 0;
	print.planeX = 0;
	print.planeY = 0.66;
	return (print);
}

void	ft_printmap(t_param *param)
{
	t_print print;

	print = set_param();
	param->running = 1;
	while (param->running)
		while(SDL_PollEvent(&param->event)) {
			if ((SDL_QUIT == param->event.type) ||
				(SDL_KEYDOWN == param->event.type && SDL_SCANCODE_ESCAPE == param->event.key.keysym.scancode))
				param->running = 0;
			for (int x = 0; x < (double) WIDTH; x++) {
				print.cameraX = 1 - 2.0 * x / (double) WIDTH;
				print.rayDirX = print.dirX + print.planeX * print.cameraX;
				print.rayDirY = print.dirY + print.planeY * print.cameraX;
				print.mapX = (int) print.posX;
				print.mapY = (int) print.posY;
				print.deltaDistX = fabs(1 / print.rayDirX);
				print.deltaDistY = fabs(1 / print.rayDirY);
				print.hit = 0;
				if (print.rayDirX < 0) {
					print.stepX = -1;
					print.sideDistX = (print.posX - print.mapX) * print.deltaDistX;
				} else {
					print.stepX = 1;
					print.sideDistX = (print.mapX + 1.0 - print.posX) * print.deltaDistX;
				}
				if (print.rayDirY < 0) {
					print.stepY = -1;
					print.sideDistY = (print.posY - print.mapY) * print.deltaDistY;
				} else {
					print.stepY = 1;
					print.sideDistY = (print.mapY + 1.0 - print.posY) * print.deltaDistY;
				}
				//perform DDA
				while (print.hit == 0) {
					//jump to next map square, OR in x-direction, OR in y-direction
					if (print.sideDistX < print.sideDistY) {
						print.sideDistX += print.deltaDistX;
						print.mapX += print.stepX;
						print.side = 0;
					} else {
						print.sideDistY += print.deltaDistY;
						print.mapY += print.stepY;
						print.side = 1;
					}
					if (param->map[print.mapY][print.mapX] == '1')
						print.hit = 1;
				}
				if (print.side == 0)
					print.perpWallDist = (print.mapX - print.posX + (1 - print.stepX) / 2) / print.rayDirX;
				else
					print.perpWallDist = (print.mapY - print.posY + (1 - print.stepY) / 2) / print.rayDirY;

				print.lineHeight = (int) (HEIGHT / print.perpWallDist);

				print.drawStart = -print.lineHeight / 2 + HEIGHT / 2;
				if (print.drawStart < 0)
					print.drawStart = 0;
				print.drawEnd = print.lineHeight / 2 + HEIGHT / 2;
				if (print.drawEnd >= HEIGHT)
					print.drawEnd = HEIGHT - 1;
				int color = 0x00FF00;
//				switch(param->map[mapX][mapY])
//				{
//					case 1:  color = 0xff0000;  break; //red
//					case 2:  color = 0x00ff00;  break; //green
//					case 3:  color = 0x0000ff;   break; //blue
//					case 4:  color = 0xffffff;  break; //white
//					default: color = 0xff8000; break; //yellow
//				}

				if (print.side == 1) { color = color / 2; }

				verLine(x, print.drawStart, print.drawEnd, color, param);
			}
				SDL_UpdateWindowSurface(param->window);
		}
}