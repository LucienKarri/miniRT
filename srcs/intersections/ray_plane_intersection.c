#include "../includes/minirt.h"

double	pl_intersection(t_vec *pos, t_vec *ray, t_pl *pl)
{
	double den;
	double t;
	t_vec	*cam_to_pl;
	
	pl->nrmd = vec_sum(pl->crd, pl->nrmd);
	vec_normalize(pl->nrmd);
	if (vec_dot_product(ray, pl->nrmd) > 0)
		pl->nrmd = vec_multiplication(pl->nrmd, -1);
	den = vec_dot_product(pl->nrmd, ray);
	if (den < 0)
	{
		cam_to_pl = vec_subtract(pl->crd, pos);
		t = vec_dot_product(pl->nrmd, cam_to_pl) / den;
		if (t >= 0)
			return (t);
	}
	return (0);
}