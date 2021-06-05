#include "../includes/minirt.h"

double	pl_intersection(t_vec *pos, t_vec *ray, t_vec *n_pl, t_vec *o_pl)
{
	double	t[3];
	t_vec	*pl_to_ray;
	t_vec	*mul;

	mul = vec_default(n_pl->x, n_pl->y, n_pl->z);
	pl_to_ray = vec_subtract(pos, o_pl);
	vec_normalize(mul);
	if (vec_dot_product(ray, mul) > 0)
	{
		free(mul);
		vec_normalize(n_pl);
		mul = vec_multiplication(n_pl, -1);
	}
	t[0] = vec_dot_product(pl_to_ray, mul);
	t[1] = vec_dot_product(ray, mul);
	free(pl_to_ray);
	free(mul);
	if (t[1] != 0)
	{
		t[2] = -t[0] / t[1];
		if (t[2] >= 0)
			return (t[2]);
	}
	return (0);
}
