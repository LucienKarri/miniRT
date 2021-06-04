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
	t_vec	*vec[2];

	vec[0] = cam_to_anything(pos, ray, inter->dist);
	if (inter->cy != NULL && inter->dist == inter->cy->distance)
		vec[1] = cy_norm1(pos, ray, inter->cy);
	if (inter->tr != NULL && inter->dist == inter->tr->distance)
		vec[1] = tr_norm(inter->tr);
	if (inter->sq != NULL && inter->dist == inter->sq->distance)
	{
		vec[1] = sq_norm(inter->sq);
		free(vec[0]);
		vec[0] = vec_subtract(*ray, *pos);
	}
	if (inter->pl != NULL && inter->dist == inter->pl->distance)
		vec[1] = pl_norm(inter->pl);
	if (inter->sp != NULL && inter->dist == inter->sp->distance)
		vec[1] = sp_norm(pos, ray, inter->sp, inter->dist);
	if (vec_dot_product(*vec[0], *vec[1]) > 0)
	{
		inter->n = vec_multiplication(*vec[1], -1);
		free(vec[1]);
	}
	else
		inter->n = vec[1];
	free(vec[0]);
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
		free(inter);
		return (0);
	}
	else
	{
		dist_inter(inter);
		n_inter(inter, ray, scene->cam->pos);
		vec_normalize(*inter->n);
		p[0] = vec_multiplication(*ray, inter->dist);
		p[1] = vec_sum(*scene->cam->pos, *p[0]);
		close_color = lightning(p[1], inter->n, scene, inter->color);
		vec_free(2, p);
		if (inter->n != NULL)
			free(inter->n);
		free(inter);
	}
	return (close_color);
}

void	ray_tracing(t_data *data, t_sc *sc)
{
	t_screen	*scr;
	t_vec		*ray[2];
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
			ray[0] = vec_default(scr->ray_x, scr->ray_y, 1);
			ray[1] = look_at(sc->cam, ray[0]);
			color = ft_intersection(sc, ray[1]);
			vec_free(2, ray);
			my_mlx_pixel_put(data, scr->mlx_x, scr->mlx_y, color);
			scr->res_x++;
			scr->mlx_x++;
		}
		scr->res_y--;
		scr->mlx_y++;
	}
	free(scr);
}
