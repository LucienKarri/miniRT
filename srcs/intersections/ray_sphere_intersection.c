#include "../includes/minirt.h"

double 	sp_crossing(t_vec *pos, t_vec *ray, t_sp *sp)
{
	double a;
	double b;
	double c;
	double discr;
	double dist_front = 0;
	double dist_back = 0;
	double dist = 100000;
	t_vec	*cam_to_sp;

	cam_to_sp = vec_subtract(pos, sp->center);
	a = vec_dot_product(ray, ray);
	b = 2 *(vec_dot_product(cam_to_sp, ray));
	c = vec_dot_product(cam_to_sp, cam_to_sp) - (sp->radius * sp->radius);
	discr = (b * b) - (4 * c * a);
	free(cam_to_sp);
	if (discr < 0)
		return (0);
	dist_front = ((b * (-1)) + sqrt(discr)) / (2 * a);
	dist_back = ((b * (-1)) - sqrt(discr)) / (2 * a);
	if (dist_front > 0 && dist_front < dist)
		dist = dist_front;
	if (dist_back > 0 && dist_back < dist)
		dist = dist_back;
	return (dist);
}