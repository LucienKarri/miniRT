#include "../includes/minirt.h"

int	lightning(t_vec *p, t_vec *n, t_sc *sc, int close_color)
{
	double	i = 0;
	t_a		*al = NULL;
	t_l		*tmp_l;
	t_vec	*light;
	double	n_to_l;
	tmp_l = sc->l;
	al = sc->a;
	t_sp	*close_sp = NULL;
	t_tr	*close_tr = NULL;
	t_pl	*close_pl = NULL;
	int	lightning = creat_color(0, 0, 0);

	p = vec_sum(p, vec_multiplication(n, 0.000001));
	lightning = light_color(lightning, al->color, al->ratio);
	while (tmp_l != NULL)
	{
		light = vec_subtract(tmp_l->v_point, p);
		close_sp = closing_sp(p, light, sc);
		close_tr = closing_tr(p, light, sc);
		close_pl = closing_pl(p, light, sc);
		if (close_sp != NULL && (close_sp->distance > 1 || close_sp->distance < 0.000001))
			close_sp = NULL;
		if (close_pl != NULL && (close_pl->distance > 1 || close_pl->distance < 0.000001))
			close_pl = NULL;
		if (close_tr != NULL && close_tr->distance > 1)
			close_tr = NULL;
		if (close_sp == NULL && close_tr == NULL && close_pl == NULL)
		{
			n_to_l = vec_dot_product(n, light);
			if (n_to_l > 0)
			{
				i = tmp_l->ratio * n_to_l / (vec_length(n) * vec_length
						(light));
				lightning = light_color(lightning, tmp_l->color, i);
			}
		}
		tmp_l = tmp_l->next;
	}
	close_color = sum_color(close_color, lightning);
	return (close_color);
}