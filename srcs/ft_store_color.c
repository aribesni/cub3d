#include "cub3d.h"

void		ft_store_color(t_calcul *calcul, t_image *image, int x)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (y < calcul->drawEnd)
	{
		while (i < y)
			i++;
		image->img_data[i * screenWidth + x] = 0x00606060;
		if (calcul->side == 1)
			image->img_data[i * screenWidth + x] = 0x00505050;
		y++;
	}
	if (calcul->drawEnd < 0)
		calcul->drawEnd = calcul->h;
	y = calcul->drawEnd;
	while (y < calcul->h)
	{
		while (i < y)
			i++;
		image->img_data[i * screenWidth + x] = 0x00329632;
		i = calcul->h - y - 1;
		image->img_data[i * screenWidth + x] = 0x00003C64;
		y++;
	}
}