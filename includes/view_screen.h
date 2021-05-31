#ifndef VIEW_SCREEN_H
# define VIEW_SCREEN_H

typedef struct s_screen
{
	double	width;
	double	hight;
	double	screen_x;
	double	screen_y;
	double	res_y;
	double	res_x;
	double	mlx_y;
	double	mlx_x;
	double	ray_x;
	double	ray_y;
	t_vec	*ray;
}				t_screen;

t_screen	*screen_default(double width, double hight, double fov);

#endif