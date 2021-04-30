#include "../includes/minirt.h"

float		ft_intersection(t_sc *scene, t_vec *ray)
{
	t_sp	*tmp_sp;
	t_sp	*close_sp = NULL;
	t_tr	*tmp_tr;
	t_tr	*close_tr = NULL;
	float	close_color = 0;
	float 	dist_sp;
	float	dist_tr;
	float	c_sp = 100000;
	float	c_tr = 100000;
	float	tmp = 100000;
	t_vec	*p;
	t_vec	*nrmd;

	tmp_sp = scene->sp;
	tmp_tr = scene->tr;
	while (tmp_sp != NULL)
	{
		dist_sp = sp_crossing(scene->cam, ray, tmp_sp);
		if (dist_sp < c_sp && dist_sp != 0)
		{
			c_sp = dist_sp;
			close_sp = tmp_sp;
		}
		tmp_sp = tmp_sp->next;
	}
	while (tmp_tr != NULL)
	{
		dist_tr = tr_crossing(scene->cam, ray, tmp_tr);
		if (dist_tr < c_tr && dist_tr != 0)
		{
			c_tr = dist_tr;
			close_tr = tmp_tr;
		}
		tmp_tr = tmp_tr->next;
	}
	if (close_tr == NULL && close_sp == NULL)
		return (0);
	if (c_sp < c_tr)
		tmp = c_sp;
	else
		tmp = c_tr;
	p = vec_sum(scene->cam->pos, vec_multiplication(ray, tmp));
	if (c_sp < c_tr)
	{
		nrmd = vec_subtract(p, close_sp->center);
		nrmd = vec_multiplication(nrmd, (1 / vec_length(nrmd)));
		close_color = close_sp->color;
	}
	else
	{
		nrmd = vec_cross(vec_subtract(close_tr->p2, close_tr->p1),
				   vec_subtract(close_tr->p3, close_tr->p1));
		close_color = close_tr->color;
	}
	return (close_color * lightning(p, nrmd, scene));
}

void	ray_tracing(void *mlx, void *window, t_sc *sc)
{
	float		mlx_x;
	float		mlx_y = 0;
	float		resolution_x;
	float		resolution_y;
	float		ray_x;
	float		ray_y;
	t_vec		*ray;
	t_screen	*scr;
	float		color;

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