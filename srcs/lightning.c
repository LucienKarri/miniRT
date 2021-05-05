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
	if (al != NULL)
	{
		i += al->ratio;
		close_color = color_mixer(close_color, al->color);
	}
	while (tmp_l != NULL)
	{
		light = vec_subtract(tmp_l->v_point, p);
		close_sp = closing_sp(p, light, sc, 1000, 100000);
		if (close_sp == NULL)
		{
			n_to_l = vec_dot_product(n, light);
			if (n_to_l > 0)
			{
				i += (tmp_l->ratio * n_to_l) / (vec_length(n) * vec_length
						(light));
//				close_color = color_mixer(close_color, tmp_l->color);
			}
//			close_color = color_mixer(close_color, tmp_l->color);
		}
		close_color = color_mixer(close_color, tmp_l->color);
		tmp_l = tmp_l->next;
	}
	if (i > 1)
		i = 1;
	close_color = mul_color(close_color, i);
	return (close_color);
}