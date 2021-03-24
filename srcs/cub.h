/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 13:02:01 by aribesni          #+#    #+#             */
/*   Updated: 2021/03/01 13:02:10 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "./libft/libft.h"
//# include "../minilibx/minilibx_linux/mlx.h"
//# include "../minilibx/minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# define true 1
# define false 0

# ifdef __linux__

#  include "../minilibx/minilibx_linux/mlx.h"
#  define UP 119
#  define DOWN 115
#  define LEFT 97
#  define RIGHT 100
#  define RTL 65361
#  define RTR 65363
#  define ESC 65307
#  define KEYPRESS 2
#  define KEYRELEASE 3
#  define KEYPRESSMASK (1L << 0)
#  define KEYRELEASEMASK (1L << 1)
#  define EXITPRESS 33
#  define EXITMASK (1L << 17)

# else

#  include "../minilibx/minilibx_opengl_20191021/mlx.h"
#  define UP 13
#  define DOWN 1
#  define LEFT 0
#  define RIGHT 2
#  define RTL 123
#  define RTR 124
#  define ESC 53
#  define KEYPRESS 2
#  define KEYRELEASE 3
#  define KEYPRESSMASK 0
#  define KEYRELEASEMASK 0
#  define EXITPRESS 17
#  define EXITMASK 10001

# endif

typedef struct		s_save
{
	int				bmp_size;
	int				bpp;
	int				hdr_size;
	int				planes;
	int				raw_size;
	int				res;
	int				start;
	int				type;
	int				*body;
	unsigned char	*header;
}					t_save;

typedef struct  	s_sprite
{
	double      	x;
	double      	y;
}               	t_sprite;

typedef struct		s_tex
{
	void			*tex_ptr;
	int				*tex_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_texture;

typedef struct		s_img
{
	void			*img_ptr;
	int				*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_image;

typedef struct		s_calcul
{
	void			*win;
	void			*mlx;
	int				w;
	int				h;
	int				mapX;
	int				mapY;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
	int				lineH;
	int				drawStart;
	int				drawEnd;
	int				up;
	int				down;
	int				left;
	int				right;
	int				rt_left;
	int				rt_right;
	int				color_c;
	int				color_f;
	int				texX;
	int 			texY;
	int 			spScreenX;
	int 			spH;
	int 			spW;
	int 			drawStartY;
	int 			drawEndY;
	int 			drawStartX;
	int 			drawEndX;
	int 			stripe;
	int				mapH;
	int				sp_count;
	int				sp_x;
	int				sp_y;
	int				save;
	int				start;
	int				*order;
	int				count_res;
	int				count_tex_no;
	int				count_tex_so;
	int				count_tex_ea;
	int				count_tex_we;
	int				count_sprite;
	int				count_pos;
	unsigned int	color;
	unsigned int	count_c;
	unsigned int	count_f;
	char			*res_x;
	char			*res_y;
	char			*color_temp;
	char			*path_tex_no;
	char			*path_tex_so;
	char			*path_tex_ea;
	char			*path_tex_we;
	char			*path_sprite;
	char			**read;
	char			**map;
	unsigned char	bit_1;
	unsigned char	bit_2;
	unsigned char	bit_3;
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	double			movSpeed;
	double			rotSpeed;
	double			cameraX;
	double			rayPosX;
	double			rayPosY;
	double			rayDirX;
	double			rayDirY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	double			perpWall;
	double			step_tex;
	double			texPos;
	double 			spriteX;
	double 			spriteY;
	double 			transX;
	double 			transY;
	double 			*dist;
	double 			*ZBuffer;
	t_image			*image;
	t_texture		*tex_no;
	t_texture		*tex_so;
	t_texture		*tex_ea;
	t_texture		*tex_we;
	t_texture		*tex_sp;
	t_sprite		*sprite;
}					t_calcul;

void				ft_add_sprite(t_calcul *calcul);
void				ft_arg(t_calcul *calcul, int argc, char **argv, int count);
void    			ft_check_path(char *path);
void				ft_convert_endian(t_calcul *calcul, char c);
void				ft_cub3d(t_calcul *calcul);
void				ft_def_world(t_calcul *calcul);
void       			ft_exit(char *str);
void				ft_file_error(t_calcul *calcul, int i, int j);
void				ft_floor_ceiling(t_calcul *calcul, int i, int j, char c);
void    			ft_free(t_calcul *calcul);
void				ft_free_img(t_calcul *calcul);
void				ft_free_save(t_calcul *calcul);
void    			ft_free_sprite(t_calcul *calcul);
void				ft_free_tex(t_calcul *calcul);
void				ft_free_tab(char **tab, int size);
void    			ft_get_rgb(char *color, unsigned char *bit);
void   				ft_init(t_calcul *calcul);
void				ft_move(t_calcul *calcul);
void				ft_set_color(t_image *image, unsigned int color, int p_x, int p_y);
void    			ft_spawn(t_calcul *calcul, char c, double x, double y);
void				ft_store_color(t_calcul *calcul, t_image *image, int x);
void				ft_texture(t_calcul *calcul);
int					ft_calculate(t_calcul *calcul);
int					ft_create_map(t_calcul *calcul, int count);
int					ft_disp_col(t_calcul *calcul, int x);
int					ft_escape(t_calcul *calcul);
int					ft_init_sprite(t_calcul *calcul);
int					ft_run(t_calcul *calcul);
int    				ft_screenshot(t_calcul *calcul);
char    			*ft_get_path(t_calcul *calcul, int i, int j);
char 			   	*ft_get_res(t_calcul *calcul, int i, int *j);
t_image				*ft_new_image(t_calcul *calcul);
t_texture			*ft_new_texture(t_calcul *calcul, char *path);

#endif
