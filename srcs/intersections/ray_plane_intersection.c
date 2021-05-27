#include "../includes/minirt.h"

double	pl_intersection(t_vec *pos, t_vec *ray, t_pl *pl)
{
	double	den1;
	double	den2;
	double	t;
//	double	dist;
//	t_vec	*cam_to_pl;
	t_vec	*pl_to_ray;
	
//	dist = 100000;
	pl_to_ray = vec_subtract(pos, pl->crd);
	vec_normalize(pl->nrmd);
	if (vec_dot_product(ray, pl->nrmd) > 0)
		pl->nrmd = vec_multiplication(pl->nrmd, -1);
	den1 = vec_dot_product(pl_to_ray, pl->nrmd);
	den2 = vec_dot_product(ray, pl->nrmd);
	if (den2 != 0)
	{
//		cam_to_pl = vec_subtract(pl->crd, pos);
//		t = vec_dot_product(pl->nrmd, cam_to_pl) / den;
		t = -den1 / den2;
		if (t >= 0)
			return (t);
	}
	return (0);
}