#include "../includes/minirt.h"

int	closest_obj(t_vec *p, t_vec *light, t_sc *sc)
{
	t_sp	*close_sp;
	t_tr	*close_tr;
	t_pl	*close_pl;
	t_sq	*close_sq;
	t_cy	*close_cy;

	close_sp = closing_sp(p, light, sc);
	close_tr = closing_tr(p, light, sc);
	close_pl = closing_pl(p, light, sc);
	close_sq = closing_sq(p, light, sc);
	close_cy = closing_cy(p, light, sc);
	if (close_sp != NULL && (close_sp->distance > 1 || close_sp->distance < 0))
		close_sp = NULL;
	if (close_pl != NULL && (close_pl->distance > 1 || close_pl->distance < 0))
		close_pl = NULL;
	if (close_tr != NULL && (close_tr->distance > 1 || close_tr->distance < 0))
		close_tr = NULL;
	if (close_sq != NULL && (close_sq->distance > 1 || close_sq->distance < 0))
		close_sq = NULL;
	if (close_cy != NULL && (close_cy->distance > 1 || close_cy->distance < 0))
		close_cy = NULL;
	if (close_sp == NULL && close_tr == NULL && close_pl
		== NULL && close_sq == NULL && close_cy == NULL)
		return (0);
	return (1);
}

int	lightning(t_vec *p, t_vec *n, t_sc *sc, int close_color)
{
	t_l		*tmp_l;
	t_vec	*light;
	double	n_to_l;
	double	i;
	int		lightning;

	tmp_l = sc->l;
	p = vec_sum(p, vec_multiplication(n, 0.000001));
	lightning = light_color(0, sc->a->color, sc->a->ratio);
	while (tmp_l != NULL)
	{
		light = vec_subtract(tmp_l->v_point, p);
		if (closest_obj(p, light, sc) == 0)
		{
			n_to_l = vec_dot_product(n, light);
			if (n_to_l > 0)
			{
				i = tmp_l->ratio * n_to_l / (vec_length(n) * vec_length(light));
				lightning = light_color(lightning, tmp_l->color, i);
			}
		}
		tmp_l = tmp_l->next;
	}
	close_color = sum_color(close_color, lightning);
	return (close_color);
}
