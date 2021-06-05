#include "../includes/minirt.h"

double	tr_crossing(t_vec *pos, t_vec *ray, t_tr *tr)
{
	t_vec	*vec[5];
	double	inv_det;
	double	det;
	double	u;
	double	v;

	vec[0] = vec_subtract(tr->p2, tr->p1);
	vec[1] = vec_subtract(tr->p3, tr->p1);
	vec[2] = vec_cross(ray, vec[1]);
	det = vec_dot_product(vec[0], vec[2]);
	if (det < 0.000001 && det > -0.000001)
		return (vec_free_zero(3, vec));
	inv_det = 1 / det;
	vec[3] = vec_subtract(pos, tr->p1);
	u = vec_dot_product(vec[3], vec[2]) * inv_det;
	if (u < 0 || u > 1)
		return (vec_free_zero(4, vec));
	vec[4] = vec_cross(vec[3], vec[0]);
	v = vec_dot_product(ray, vec[4]) * inv_det;
	if (v < 0 || u + v > 1)
		return (vec_free_zero(5, vec));
	det = vec_dot_product(vec[1], vec[4]) * inv_det;
	vec_free(5, vec);
	return (det);
}
