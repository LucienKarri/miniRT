#include "../includes/minirt.h"

int		ft_intersection(t_sc *scene, t_vec *ray)
{
	t_sp	*close_sp = NULL;
	float	c_sp = 100000;
	t_tr	*close_tr = NULL;
	float	c_tr = 100000;
	t_pl	*close_pl = NULL;
	float	c_pl = 100000;
	int 	close_color = 0;
	float	tmp = 100000;
	t_vec	*p;
	t_vec	*nrmd;

	close_sp = closing_sp(scene->cam->pos, ray, scene, 1, 100000);
	close_tr = closing_tr(scene->cam->pos, ray, scene);
	close_pl = closing_pl(scene->cam->pos, ray, scene);
	if (close_tr == NULL && close_sp == NULL && close_pl == NULL)
		return (0);
	if (close_tr != NULL)
		c_tr = close_tr->distance;
	if (close_sp != NULL)
		c_sp = close_sp->distance;
	if (close_pl != NULL)
		c_pl = close_pl->distance;
	if (c_sp < c_tr)
	{
		if (c_sp < c_pl)
			tmp = c_sp;
	}
	else if (c_tr < c_sp)
	{
		if (c_tr < c_pl)
			tmp = c_tr;
	}
	else
		tmp = c_pl;
	p = vec_sum(scene->cam->pos, vec_multiplication(ray, tmp));
	if (tmp == c_sp)
	{
		nrmd = vec_subtract(p, close_sp->center);
		vec_normalize(nrmd);
		close_color = close_sp->color;
	}
	else if (tmp == c_tr)
	{
		nrmd = vec_cross(vec_subtract(close_tr->p2, close_tr->p1),
				   vec_subtract(close_tr->p3, close_tr->p1));
		vec_normalize(nrmd);
		close_color = close_tr->color;
	}
	else
	{
		nrmd = close_pl->nrmd;
//		vec_normalize(nrmd);
		close_color = close_pl->color;
	}
	close_color = lightning(p, nrmd, scene, close_color);
	return (close_color);
}

void	ray_tracing(t_data *data, t_sc *sc)
{
	float		mlx_x;
	float		mlx_y = 0;
	float		resolution_x;
	float		resolution_y;
	float		ray_x;
	float		ray_y;
	t_vec		*ray;
	t_screen	*scr;
	int			color;

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
			ray = vec_default(ray_x, ray_y, 1);
			vec_normalize(ray);
			ray = look_at(sc->cam, ray);
			vec_normalize(ray);
			color = ft_intersection(sc, ray);
			my_mlx_pixel_put(data, mlx_x, mlx_y, color);
			free(ray);
			resolution_x++;
			mlx_x++;
		}
		resolution_y--;
		mlx_y++;
	}
}