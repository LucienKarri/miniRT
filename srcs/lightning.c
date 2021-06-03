#include "../includes/minirt.h"

int	closest_obj(t_vec *p, t_vec *light, t_sc *sc)
{
    t_inter *inter;

    inter = new_inter();
	inter->sp = closing_sp(p, light, sc);
	inter->tr = closing_tr(p, light, sc);
	inter->pl = closing_pl(p, light, sc);
	inter->sq = closing_sq(p, light, sc);
	inter->cy = closing_cy(p, light, sc);
	if (inter->sp != NULL && (inter->sp->distance > 1 || inter->sp->distance < 0))
		inter->sp = NULL;
	if (inter->pl != NULL && (inter->pl->distance > 1 || inter->pl->distance < 0))
		inter->pl = NULL;
	if (inter->tr != NULL && (inter->tr->distance > 1 || inter->tr->distance < 0))
		inter->tr = NULL;
	if (inter->sq != NULL && (inter->sq->distance > 1 || inter->sq->distance < 0))
		inter->sq = NULL;
	if (inter->cy != NULL && (inter->cy->distance > 1 || inter->cy->distance < 0))
		inter->cy = NULL;
	if (inter->sp == NULL && inter->tr == NULL && inter->pl
		== NULL && inter->sq == NULL && inter->cy == NULL)
    {
        free(inter);
        return (0);
    }
    free(inter);
	return (1);
}

int	lightning(t_vec *p, t_vec *n, t_sc *sc, int close_color)
{
	t_l		*tmp_l;
	double	n_to_l;
	double	i;
	int		lightning;
    t_vec   *vec[2];

	tmp_l = sc->l;
    vec[0] = vec_multiplication(*n, 0.000001);
	vec[1] = vec_sum(*p, *vec[0]);
    free(vec[0]);
	lightning = light_color(0, sc->a->color, sc->a->ratio);
	while (tmp_l != NULL)
	{
		vec[0] = vec_subtract(*tmp_l->v_point, *vec[1]);
		if (closest_obj(vec[1], vec[0], sc) == 0)
		{
			n_to_l = vec_dot_product(*n, *vec[0]);
			if (n_to_l > 0)
			{
				i = tmp_l->ratio * n_to_l / (vec_length(*n) * vec_length(*vec[0]));
				lightning = light_color(lightning, tmp_l->color, i);
			}
		}
        free(vec[0]);
		tmp_l = tmp_l->next;
	}
	close_color = sum_color(close_color, lightning);
    free(vec[1]);
    free(tmp_l);
	return (close_color);
}
