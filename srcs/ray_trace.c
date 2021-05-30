#include "../includes/minirt.h"

int		ft_intersection(t_sc *scene, t_vec *ray)
{
	t_sp	*close_sp = NULL;
	double	c_sp = 100000;
	t_tr	*close_tr = NULL;
	double	c_tr = 100000;
	t_pl	*close_pl = NULL;
	double	c_pl = 100000;
	t_sq	*close_sq = NULL;
	double	c_sq = 100000;
	t_cy	*close_cy = NULL;
	double	c_cy = 100000;
	int 	close_color = 0;
	double	tmp = 100000;
	t_vec	*p;
	t_vec	*nrmd;
	t_vec	*cam_to;

	close_sp = closing_sp(scene->cam->pos, ray, scene);
	if (close_sp != NULL && (close_sp->distance < 1 || close_sp->distance > 100000))
		close_sp = NULL;
	close_tr = closing_tr(scene->cam->pos, ray, scene);
	close_pl = closing_pl(scene->cam->pos, ray, scene);
	close_sq = closing_sq(scene->cam->pos, ray, scene);
	close_cy = closing_cy(scene->cam->pos, ray, scene);
//	if (close_cy != NULL)
//		printf("%f, %f, %f; %f\n", close_cy->origin->x, close_cy->origin->y, close_cy->origin->z, close_cy->distance);
	if (close_tr == NULL && close_sp == NULL && close_pl == NULL && close_sq == NULL && close_cy == NULL)
		return (0);
	else
	{
		if (close_tr != NULL)
			c_tr = close_tr->distance;
		if (close_sp != NULL)
			c_sp = close_sp->distance;
		if (close_pl != NULL)
			c_pl = close_pl->distance;
		if (close_sq != NULL)
			c_sq = close_sq->distance;
		if (close_cy != NULL)
			c_cy = close_cy->distance;
		if (c_sp < tmp)
			tmp = c_sp;
		if (c_tr < tmp)
			tmp = c_tr;
		if (c_pl < tmp)
			tmp = c_pl;
		if (c_sq < tmp)
			tmp = c_sq;
		if (c_cy < tmp)
			tmp = c_cy;
		p = vec_sum(scene->cam->pos, vec_multiplication(ray, tmp));
		if (tmp == c_cy && close_cy != NULL)
		{
			nrmd = close_cy->li;
			cam_to = vec_subtract(ray, scene->cam->pos);
			if (vec_dot_product(cam_to, nrmd) > 0)
				nrmd = vec_multiplication(nrmd, -1);
			vec_normalize(nrmd);
			close_color = close_cy->color;
		}
		if (tmp == c_sp && close_sp != NULL)
		{
			nrmd = vec_subtract(p, close_sp->center);
			vec_normalize(nrmd);
			close_color = close_sp->color;
		}
		if (tmp == c_tr && close_tr != NULL)
		{
			nrmd = vec_cross(vec_subtract(close_tr->p2, close_tr->p1),
				   vec_subtract(close_tr->p3, close_tr->p1));
			cam_to = vec_subtract(p, scene->cam->pos);
			if (vec_dot_product(cam_to, nrmd) > 0)
				nrmd = vec_multiplication(nrmd, -1);
			vec_normalize(nrmd);
			close_color = close_tr->color;
		}
		if (tmp == c_pl && close_pl != NULL)
		{
			nrmd = close_pl->nrmd;
			cam_to = vec_subtract(ray, scene->cam->pos);
			if (vec_dot_product(cam_to, nrmd) > 0)
				nrmd = vec_multiplication(nrmd, -1);
			vec_normalize(nrmd);
			close_color = close_pl->color;
		}
		if (tmp == c_sq && close_sq != NULL)
		{
			nrmd = close_sq->nrmd;
			cam_to = vec_subtract(ray, scene->cam->pos);
			if (vec_dot_product(cam_to, nrmd) > 0)
				nrmd = vec_multiplication(nrmd, -1);
			vec_normalize(nrmd);
			close_color = close_sq->color;
		}
		close_color = lightning(p, nrmd, scene, close_color);
	}
	return (close_color);
}

void	ray_tracing(t_data *data, t_sc *sc)
{
	double		mlx_x;
	double		mlx_y = 0;
	double		resolution_x;
	double		resolution_y;
	double		ray_x;
	double		ray_y;
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