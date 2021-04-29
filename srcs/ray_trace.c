#include "../includes/minirt.h"

int		ft_intersection(t_sc *scene, t_vec *ray)
{
	t_sp	*close_sp = NULL;
	t_sp	*tmp_sp;
	float 	dist;
	float	tmp = 100000;

	tmp_sp = scene->sp;
	while (tmp_sp != NULL)
	{
		dist = sp_crossing(scene->cam, ray, tmp_sp);
//		printf("%f\n", dist);
		if (dist < tmp && dist != 0)
		{
			tmp = dist;
			close_sp = tmp_sp;
		}
		tmp_sp = tmp_sp->next;
	}
	if (close_sp == NULL)
		return (0);
	return (close_sp->color);
}

void	ray_tracing(void *mlx, void *window, t_sc *sc)
{
	int			mlx_x;
	int			mlx_y = 0;
	float		resolution_x;
	float		resolution_y;
	float		ray_x;
	float		ray_y;
	t_vec		*ray;
	t_screen	*scr;
	int 		color;

	scr = screen_default(sc->width, sc->hight, sc->cam->fov);
	resolution_y = (sc->hight / 2);
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
			color = ft_intersection(sc, ray);
//			if (ft_intersection(sc, ray) == 1)
//				color = 7234567;
//			else
//				color = 0;
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
			free(ray);
			resolution_x++;
			mlx_x++;
		}
		resolution_y--;
		mlx_y++;
	}
}