#include "../includes/minirt.h"

double	pl_intersection(t_vec *pos, t_vec *ray, t_vec *n_pl, t_vec *o_pl)
{
	double	den1;
	double	den2;
	double	t;
	t_vec	*pl_to_ray;
	
	pl_to_ray = vec_subtract(pos, o_pl);
	vec_normalize(n_pl);
	if (vec_dot_product(ray, n_pl) > 0)
		n_pl = vec_multiplication(n_pl, -1);
	den1 = vec_dot_product(pl_to_ray, n_pl);
	den2 = vec_dot_product(ray, n_pl);
	if (den2 != 0)
	{
		t = -den1 / den2;
		if (t >= 0)
			return (t);
	}
	return (0);
}