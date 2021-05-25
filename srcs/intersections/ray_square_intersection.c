#include "../includes/minirt.h"

float	sq_intersection(t_vec *pos, t_vec *ray, t_sq *sq)
{
	float den;
	float t;
	t_vec	*cam_to_sq;
	t_vec	*hit;
	t_vec	*dir;
	t_vec	*right;
	t_vec	*up;
	t_vec	*hit_center;
	float	hc;
	float	ca;
	float	a;

	den = vec_dot_product(sq->nrmd, ray);
	if (den > 0.000001)
	{
		cam_to_sq = vec_subtract(sq->center, pos);
		t = vec_dot_product(cam_to_sq, sq->nrmd) / den;
		if (t >= 0)
		{
			hit = vec_multiplication(ray, t);
			dir = vec_subtract(sq->nrmd, sq->center);
			right = cam_right(dir);
			up = cam_up(right, dir);
			hit_center = vec_subtract(hit, sq->center);
			ca = vec_dot_product(hit_center, right) / vec_length(hit_center) / vec_length (right);
			a = acos(ca);
			
		}
	}
	return (0);
}