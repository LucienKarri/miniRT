#include "../includes/minirt.h"

int		ft_intersection(t_sc *scene, t_vec *ray)
{
//	t_sp	*close_sp = NULL;
	t_sp	*tmp_sp;
//	t_tr	*close_tr = NULL;
	t_tr	*tmp_tr;
	int		close_color = 0;
	float 	dist_sp;
	float	dist_tr;
	float	tmp = 100000;

	tmp_sp = scene->sp;
	tmp_tr = scene->tr;
	while (tmp_sp != NULL)
	{
		dist_sp = sp_crossing(scene->cam, ray, tmp_sp);
		if (dist_sp < tmp && dist_sp != 0)
		{
			tmp = dist_sp;
			close_color = tmp_sp->color;
		}
		tmp_sp = tmp_sp->next;
	}
	while (tmp_tr != NULL)
	{
		dist_tr = tr_crossing(scene->cam, ray, tmp_tr);
		if (dist_tr < tmp && dist_tr != 0)
		{
			tmp = dist_tr;
			close_color = tmp_tr->color;
		}
		tmp_tr = tmp_tr->next;
	}
//	if (close_color == NULL)
//		return (0);
	return (close_color);
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
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
			free(ray);
			resolution_x++;
			mlx_x++;
		}
		resolution_y--;
		mlx_y++;
	}
}