#include "../includes/minirt.h"

t_screen	*screen_default(double width, double hight, double fov)
{
	t_screen	*screen;
	double		ratio;

	screen = malloc(sizeof(t_screen));
	if (!screen)
		error_and_exit(-1);
	ratio = width / hight;
	screen->width = tan(fov / 2 * (M_PI / 180));
	screen->width *= 2;
	screen->hight = screen->width / ratio;
	screen->screen_x = screen->width / width;
	screen->screen_y = screen->hight / hight;
	screen->res_y = hight / 2;
	screen->res_x = (width / 2) * (-1);
	screen->mlx_x = 0;
	screen->mlx_y = 0;
	screen->ray_x = 0;
	screen->ray_y = 0;
	screen->ray = NULL;
	return (screen);
}
