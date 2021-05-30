#include "../includes/minirt.h"

double	sq_intersection(t_vec *pos, t_vec *ray, t_sq *sq)
{
	double	dist;
	double	vcos;
	double	max;
	t_vec	*point;
	t_vec	*s;
	t_vec	*cam_to_sq;

	dist = pl_intersection(pos, ray, sq->nrmd, sq->center);
	point = vec_sum(pos, vec_multiplication(ray, dist));
	s = cam_right(sq->nrmd);
	cam_to_sq = vec_subtract(point, sq->center);
	vcos = fabs(vec_dot_product(s, cam_to_sq) / (vec_length(s) * vec_length(cam_to_sq)));
	if (vcos < sqrt(2) / 2)
		vcos = cos(M_PI_2 - acos(vcos));
	max = (sq->side / 2) / vcos;
	if (sqrt(vec_dot_product(cam_to_sq, cam_to_sq)) <= max)
		return (dist);
	return (0);
}