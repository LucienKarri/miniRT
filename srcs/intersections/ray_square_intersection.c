#include "../includes/minirt.h"

double	sq_intersection(t_vec *pos, t_vec *ray, t_sq *sq)
{
	double	dist;
	double	vcos;
	double	max;
	t_vec	*vec[4];

	dist = pl_intersection(pos, ray, sq->nrmd, sq->center);
	vec[0] = cam_right(sq->nrmd);
	vec[1] = vec_multiplication(ray, dist);
	vec[2] = vec_sum(pos, vec[1]);
	vec[3] = vec_subtract(vec[2], sq->center);
	vcos = fabs(vec_dot_product(vec[0], vec[3])
			/ (vec_length(vec[0]) * vec_length(vec[3])));
	if (vcos < sqrt(2) / 2)
		vcos = cos(M_PI_2 - acos(vcos));
	max = (sq->side / 2) / vcos;
	if (sqrt(vec_dot_product(vec[3], vec[3])) <= max)
	{
		vec_free(4, vec);
		return (dist);
	}
	vec_free(4, vec);
	return (0);
}
