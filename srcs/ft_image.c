#include "cub3d.h"

t_image	*ft_new_image(t_calcul *calcul)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	image->img_ptr = mlx_new_image(calcul->mlx, screenWidth, screenHeight);
	image->img_data = (int *)mlx_get_data_addr(image->img_ptr, &image->bpp, &image->size_line, &image->endian);
	image->width = screenWidth;
	image->height = screenHeight;
	return (image);
}

void	ft_free_img(t_calcul *calcul)
{
	if (calcul->image)
	{
		mlx_destroy_image(calcul->mlx, calcul->image->img_ptr);
		free(calcul->image);
		calcul->image = NULL;
	}
}