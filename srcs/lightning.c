#include "../includes/minirt.h"

int	closest_obj(t_vec *p, t_vec *light, t_sc *sc)
{
	t_inter	*i;

	i = new_inter();
	i->sp = closing_sp(p, light, sc);
	i->tr = closing_tr(p, light, sc);
	i->pl = closing_pl(p, light, sc);
	i->sq = closing_sq(p, light, sc);
	i->cy = closing_cy(p, light, sc);
	if (i->sp != NULL && (i->sp->distance > 1 || i->sp->distance < 0))
		i->sp = NULL;
	if (i->pl != NULL && (i->pl->distance > 1 || i->pl->distance < 0))
		i->pl = NULL;
	if (i->tr != NULL && (i->tr->distance > 1 || i->tr->distance < 0))
		i->tr = NULL;
	if (i->sq != NULL && (i->sq->distance > 1 || i->sq->distance < 0))
		i->sq = NULL;
	if (i->cy != NULL && (i->cy->distance > 1 || i->cy->distance < 0))
		i->cy = NULL;
	if (i->sp == NULL && i->tr == NULL && i->pl
		== NULL && i->sq == NULL && i->cy == NULL)
		return (inter_free(i));
	free(i);
	return (1);
}

int	ret_col(int light, t_sc *sc, t_vec *n, t_vec *p)
{
	t_l		*tmp_l;
	double	n_to_l;
	double	i;
	t_vec	*vec;

	tmp_l = sc->l;
	while (tmp_l != NULL)
	{
		vec = vec_subtract(*tmp_l->v_point, *p);
		if (closest_obj(p, vec, sc) == 0)
		{
			n_to_l = vec_dot_product(*n, *vec);
			if (n_to_l > 0)
			{
				i = tmp_l->ratio * n_to_l / (vec_length(*n) * vec_length(*vec));
				light = light_color(light, tmp_l->color, i);
			}
		}
		free(vec);
		tmp_l = tmp_l->next;
	}
	return (light);
}

int	lightning(t_vec *p, t_vec *n, t_sc *sc, int close_color)
{
	int		light;
	t_vec	*vec[2];

	vec[0] = vec_multiplication(*n, 0.000001);
	vec[1] = vec_sum(*p, *vec[0]);
	free(vec[0]);
	light = light_color(0, sc->a->color, sc->a->ratio);
	light = ret_col(light, sc, n, vec[1]);
	close_color = sum_color(close_color, light);
	free(vec[1]);
	return (close_color);
}
