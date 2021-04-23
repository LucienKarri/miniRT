#include "../includes/minirt.h"

void	ray_tracing(void *mlx, void *window, t_sc *sc)
{
	int			mlx_x;
	int			mlx_y = 0;
	float		resolution_x;
	float		resolution_y;
	int 		color;
	float		ray_x;
	float		ray_y;
	t_vec		*ray;
	t_screen	*scr;

	scr = screen_default(sc->width, sc->hight, sc->cam->fov);
	resolution_y = sc->hight / 2;
	while (resolution_y >= (sc->hight / 2) * (-1))
	{
		ray_y = resolution_y * scr->screen_y;
		resolution_x = (sc->width / 2) * (-1);
		mlx_x = 0;
		while (resolution_x <= sc->width / 2)
		{
			ray_x = resolution_x * scr->screen_x;
			ray = vec_default(ray_x, ray_y, -1);
			vec_normalize(ray);
			if (sp_crossing(sc->cam, ray, sc->sp))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
			free(ray);
			resolution_x++;
			mlx_x++;
		}
		resolution_y--;
		mlx_y++;
	}
}