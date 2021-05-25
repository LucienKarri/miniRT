#include "../includes/minirt.h"

int	lightning(t_vec *p, t_vec *n, t_sc *sc, int close_color)
{
	float	i = 0;
	t_a		*al = NULL;
	t_l		*tmp_l;
	t_vec	*light;
	float	n_to_l;
	tmp_l = sc->l;
	al = sc->a;
	t_sp	*close_sp = NULL;
	t_tr	*close_tr = NULL;
	t_pl	*close_pl = NULL;

	if (al != NULL)
	{
		i += al->ratio;
		close_color = color_mixer(close_color, al->color);
	}
	int		close_color1 = close_color;
	while (tmp_l != NULL)
	{
		light = vec_subtract(tmp_l->v_point, p);
		vec_normalize(light);
		close_sp = closing_sp(p, light, sc, 0.1, 100000);
		close_tr = closing_tr(p, light, sc);
		close_pl = closing_pl(p, light, sc);
		if (close_sp == NULL && close_tr == NULL && close_pl == NULL)
		{
			n_to_l = vec_dot_product(n, light);
			if (n_to_l > 0)
				i += (tmp_l->ratio * n_to_l) / (vec_length(n) * vec_length
						(light));
		}
		close_color1 = color_mixer(close_color1, tmp_l->color);
		tmp_l = tmp_l->next;
	}
	if (i > 1)
		i = 1;
	close_color = color_mixer(close_color, close_color1);
	close_color = mul_color(close_color, i);
	return (close_color);
}