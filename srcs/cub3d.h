#ifndef CUB3D
# define CUB3D

# include "../minilibx/minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define screenWidth 960
# define screenHeight 480
# define mapWidth 24
# define mapHeight 24
# define true 1
# define false 0
# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK 0
# define KEYRELEASEMASK 0
# define EXITMASK 10001

typedef struct				s_img
{
	void					*img_ptr;
	int						*img_data;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
}							t_image;

typedef struct		s_calcul
{
	void			*win;
	void			*mlx;
	void			*img;
	int				*pix;
	int 			w;
	int 			h;
	int				x;
	int				y;
	int				mapX;
	int				mapY;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
	int				hauteurLigne;
	int				drawStart;
	int				drawEnd;
	int				color;
	int				key;
	int				up;
	int				down;
	int				left;
	int	            right;
	int				rt_left;
	int				rt_right;
	int				**map;
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	double			oldDirX;
	double			oldPlaneX;
	double			vitMarche;
	double			vitRotation;
	double			cameraX;
	double			rayPosX;
	double			rayPosY;
	double			rayDirX;
	double			rayDirY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	double			perpWallDist;
	t_image			*image;
}					t_calcul;

void	        ft_move(t_calcul *calcul);
void			ft_calculate(t_calcul *calcul);
void			ft_store_color(t_calcul *calcul, t_image *image, int x);
void			ft_key_events(t_calcul *calcul);
void			ft_free_img(t_calcul *calcul);
t_image			*ft_new_image(t_calcul *calcul);


#endif
