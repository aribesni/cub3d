#include "cub3d.h"

static int		ft_run(t_calcul *calcul)
{
	ft_free_img(calcul);
	calcul->image = ft_new_image(calcul);
	ft_move(calcul);
	ft_calculate(calcul);
	mlx_put_image_to_window(calcul->mlx, calcul->win, calcul->image->img_ptr, 0, 0);
	return (1);
}

static int		ft_escape(t_calcul *calcul)
{
	ft_free_img(calcul);
	mlx_clear_window(calcul->mlx, calcul->win);
	if (calcul->win)
		mlx_destroy_window(calcul->mlx, calcul->win);
	if (calcul->mlx)
		free(calcul->mlx);
	exit(1);
	return (1);
}

static int			ft_key_press(int keycode, t_calcul *calcul)
{
	if (keycode == 13)
		calcul->up = true;
	if (keycode == 1)
		calcul->down = true;
	if (keycode == 2)
		calcul->right = true;
	if (keycode == 0)
		calcul->left = true;
	if (keycode == 123)
		calcul->rt_left = true;
	if (keycode == 124)
		calcul->rt_right = true;
	if (keycode == 53)
		ft_escape(calcul);
	return (1);
}

static int			ft_key_release(int keycode, t_calcul *calcul)
{
	if (keycode == 13)
		calcul->up = false;
	if (keycode == 1)
		calcul->down = false;
	if (keycode == 2)
		calcul->right = false;
	if (keycode == 0)
		calcul->left = false;
	if (keycode == 123)
		calcul->rt_left = false;
	if (keycode == 124)
		calcul->rt_right = false;
	return (1);
}

void		ft_key_events(t_calcul *calcul)
{
	if (!(calcul->mlx = mlx_init()))
		return ;
	if (!(calcul->win = mlx_new_window(calcul->mlx, screenWidth, screenHeight, "Cub3D")))
		return ;
	mlx_hook(calcul->win, KEYPRESS, KEYPRESSMASK, ft_key_press, calcul);
	mlx_hook(calcul->win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, calcul);
	mlx_hook(calcul->win, 17, EXITMASK, ft_escape, calcul);
	mlx_loop_hook(calcul->mlx, ft_run, calcul);
	mlx_loop(calcul->mlx);
}