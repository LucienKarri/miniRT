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

	cam_to = vec_subtract(vec_sum(pos, vec_multiplication(ray, inter->dist)), pos);
	if (inter->cy != NULL && inter->dist == inter->cy->distance)
		inter->n = inter->cy->li;
	if (inter->tr != NULL && inter->dist == inter->tr->distance)
		inter->n = vec_cross(vec_subtract(inter->tr->p2, inter->tr->p1),
				   vec_subtract(inter->tr->p3, inter->tr->p1));
	if (inter->sq != NULL && inter->dist == inter->sq->distance)
	{
		inter->n = inter->sq->nrmd;
		cam_to = vec_subtract(ray, pos);
	}
	if (inter->pl != NULL && inter->dist == inter->pl->distance)
		inter->n = inter->pl->nrmd;
	if (inter->sp != NULL && inter->dist == inter->sp->distance)
		inter->n = vec_subtract(vec_sum(pos, vec_multiplication(ray, inter->dist)), inter->sp->center);
	if (vec_dot_product(cam_to, inter->n) > 0)
		inter->n = vec_multiplication(inter->n, -1);
	free(cam_to);
	vec_normalize(inter->n);
}

int	ft_intersection(t_sc *scene, t_vec *ray)
{
	t_inter	*inter;
	t_vec	*p;
	int		close_color;

	inter = new_inter();
	close_color = 0;
	if (close_inter(scene->cam->pos, ray, scene, inter) == 0)
		return (0);
	else
	{
		dist_inter(inter);
		n_inter(inter, ray, scene->cam->pos);
		p = vec_sum(scene->cam->pos, vec_multiplication(ray, inter->dist));
		close_color = lightning(p, inter->n, scene, inter->color);
	}
	free(inter);
	free(p);
	return (close_color);
}

void	ray_tracing(t_data *data, t_sc *sc)
{
	t_screen	*scr;
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
			scr->ray = vec_default(scr->ray_x, scr->ray_y, 1);
			vec_normalize(scr->ray);
			scr->ray = look_at(sc->cam, scr->ray);
			vec_normalize(scr->ray);
			color = ft_intersection(sc, scr->ray);
			my_mlx_pixel_put(data, scr->mlx_x, scr->mlx_y, color);
			scr->res_x++;
			scr->mlx_x++;
		}
		scr->res_y--;
		scr->mlx_y++;
	}
	free(scr);
}
