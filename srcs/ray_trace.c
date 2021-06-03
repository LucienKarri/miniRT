#include "../includes/minirt.h"

int	close_inter(t_vec *pos, t_vec *ray, t_sc *sc, t_inter *inter)
{
	inter->sp = closing_sp(pos, ray, sc);
	if (inter->sp != NULL && (inter->sp->distance < 1
			|| inter->sp->distance > 100000))
		inter->sp = NULL;
	inter->tr = closing_tr(pos, ray, sc);
	inter->pl = closing_pl(pos, ray, sc);
	inter->sq = closing_sq(pos, ray, sc);
	inter->cy = closing_cy(pos, ray, sc);
	if (inter->tr == NULL && inter->sp == NULL && inter->pl
		== NULL && inter->sq == NULL && inter->cy == NULL)
		return (0);
	else
		return (1);
}

void	dist_inter(t_inter *inter)
{
	if (inter->tr != NULL && inter->tr->distance < inter->dist)
	{
		inter->dist = inter->tr->distance;
		inter->color = inter->tr->color;
	}
	if (inter->sp != NULL && inter->sp->distance < inter->dist)
	{
		inter->dist = inter->sp->distance;
		inter->color = inter->sp->color;
	}
	if (inter->pl != NULL && inter->pl->distance < inter->dist)
	{
		inter->dist = inter->pl->distance;
		inter->color = inter->pl->color;
	}
	if (inter->sq != NULL && inter->sq->distance < inter->dist)
	{
		inter->dist = inter->sq->distance;
		inter->color = inter->sq->color;
	}
	if (inter->cy != NULL && inter->cy->distance < inter->dist)
	{
		inter->dist = inter->cy->distance;
		inter->color = inter->cy->color;
	}
}

void	n_inter(t_inter *inter, t_vec *ray, t_vec *pos)
{
	t_vec	*cam_to;
	t_vec	*vec[2];
	t_vec	*vec1[2];
	t_vec   *n;

	vec1[0] = vec_multiplication(*ray, inter->dist);
	vec1[1] = vec_sum(*pos, *vec1[0]);
	cam_to = vec_subtract(*vec1[1], *pos);
	vec_free(2, vec1);
	if (inter->cy != NULL && inter->dist == inter->cy->distance)
		n = cy_norm1(pos, ray, inter->cy);
//		n = vec_default(inter->cy->li->x, inter->cy->li->y, inter->cy->li->z);
//		n = inter->cy->li;
	if (inter->tr != NULL && inter->dist == inter->tr->distance)
	{
		vec[0] = vec_subtract(*inter->tr->p2, *inter->tr->p1);
		vec[1] = vec_subtract(*inter->tr->p3, *inter->tr->p1);
		n = vec_cross(*vec[0], *vec[1]);
		vec_free(2, vec);
	}
	if (inter->sq != NULL && inter->dist == inter->sq->distance)
	{
		n = vec_default(inter->sq->nrmd->x,inter->sq->nrmd->y, inter->sq->nrmd->z);
	//	n = inter->sq->nrmd;
		free(cam_to);
		cam_to = vec_subtract(*ray, *pos);
	}
	if (inter->pl != NULL && inter->dist == inter->pl->distance)
		n = vec_default(inter->pl->nrmd->x, inter->pl->nrmd->y, inter->pl->nrmd->z);
	//	n = inter->pl->nrmd;
	if (inter->sp != NULL && inter->dist == inter->sp->distance)
	{
		vec[0] = vec_multiplication(*ray, inter->dist);
		vec[1] = vec_sum(*pos, *vec[0]);
		n = vec_subtract(*vec[1], *inter->sp->center);
		vec_free(2, vec);
	}
	if (vec_dot_product(*cam_to, *n) > 0)
	{
		inter->n = vec_multiplication(*n, -1);
		free(n);
	}
	else
		inter->n = n;
	free(cam_to);
	vec_normalize(*inter->n);
}

int	ft_intersection(t_sc *scene, t_vec *ray)
{
	t_inter	*inter;
	t_vec	*p[2];
	int		close_color;

	inter = new_inter();
	close_color = 0;
	if (close_inter(scene->cam->pos, ray, scene, inter) == 0)
	{
//		if(inter->cy != NULL)
//			free(inter->cy->li);
		free(inter);
		return (0);
	}
	else
	{
		dist_inter(inter);
		n_inter(inter, ray, scene->cam->pos);
		p[0] = vec_multiplication(*ray, inter->dist);
		p[1] = vec_sum(*scene->cam->pos, *p[0]);
		close_color = lightning(p[1], inter->n, scene, inter->color);
		vec_free(2, p);
//		if(inter->cy != NULL)
//			free(inter->cy->li);
		if (inter->n != NULL)
			free(inter->n);
		free(inter);
	}
//	if(inter->cy != NULL)
//		free(inter->cy->li);
//	free(inter);
	return (close_color);
}

void	ray_tracing(t_data *data, t_sc *sc)
{
	t_screen	*scr;
	t_vec		*ray;
	t_vec		*new_ray;
	int			color;

	scr = screen_default(sc->width, sc->hight, sc->cam->fov);
	while (scr->res_y >= (sc->hight / 2) * (-1))
	{
		scr->ray_y = scr->res_y * scr->screen_y;
		scr->res_x = (sc->width / 2) * (-1);
		scr->mlx_x = 0;
		while (scr->res_x <= sc->width / 2)
		{
			scr->ray_x = scr->res_x * scr->screen_x;
		//	ray = vec_default(scr->ray_x, scr->ray_y, 1);
		//	vec_normalize(*ray);
			new_ray = vec_default(scr->ray_x, scr->ray_y, 1);
			ray = look_at(sc->cam, new_ray);
			vec_normalize(*ray);
			color = ft_intersection(sc, ray);
			free(new_ray);
			free(ray);
			my_mlx_pixel_put(data, scr->mlx_x, scr->mlx_y, color);
			scr->res_x++;
			scr->mlx_x++;
		}
		scr->res_y--;
		scr->mlx_y++;
	}
	free(scr);
}
