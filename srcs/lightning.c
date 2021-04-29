#include "../includes/minirt.h"

float	lightning(t_vec *p, t_vec *n, t_sc *sc)
{
	float	i = 0;
	t_a		*al = NULL;
	t_l		*tmp_l;
	t_vec	*light;
	float	n_to_l;
	tmp_l = sc->l;
	al = sc->a;
	if (al != NULL)
		i += al->ratio;
	while (tmp_l != NULL)
	{
		light = vec_subtract(tmp_l->v_point, p);
		n_to_l = vec_dot_product(n, light);
		if (n_to_l > 0)
			i += (tmp_l->ratio * n_to_l / (vec_length(n) * vec_length
					(light)));
		tmp_l = tmp_l->next;
	}
	return (i);
}