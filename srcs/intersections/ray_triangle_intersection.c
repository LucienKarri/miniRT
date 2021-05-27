#include "../includes/minirt.h"

double	tr_crossing(t_vec *pos, t_vec *ray, t_tr *tr)
{
	t_vec	*edge1;
	t_vec	*edge2;
	t_vec	*pvec;
	t_vec	*tvec;
	t_vec	*qvec;
	double	inv_det;
	double	det;
	double	u;
	double	v;
	double	dist;

	dist = 0;
	edge1 = vec_subtract(tr->p2, tr->p1);
	edge2 = vec_subtract(tr->p3, tr->p1);
	pvec = vec_cross(ray, edge2);
	det = vec_dot_product(edge1, pvec);
	if (det < 0.000001 && det > -0.000001)
		return (0);
	inv_det = 1 / det;
	tvec = vec_subtract(pos, tr->p1);
	u = vec_dot_product(tvec, pvec) * inv_det;
	if (u < 0 || u > 1)
		return (0);
	qvec = vec_cross(tvec, edge1);
	v = vec_dot_product(ray, qvec) * inv_det;
	if (v < 0 || u + v > 1)
		return (0);
	dist = vec_dot_product(edge2, qvec) * inv_det;
	return (dist);
}