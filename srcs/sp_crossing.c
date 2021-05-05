#include "../includes/minirt.h"

float 	sp_crossing(t_vec *pos, t_vec *ray, t_sp *sp, float min, float max)
{
	float a;
	float b;
	float c;
	float discr;
	float dist_front = 0;
	float dist_back = 0;
	float dist = 100000;
	t_vec	*cam_to_sp;

	cam_to_sp = vec_subtract(pos, sp->center);
	a = vec_dot_product(ray, ray);
	b = 2 *(vec_dot_product(cam_to_sp, ray));
	c = vec_dot_product(cam_to_sp, cam_to_sp) - (sp->radius * sp->radius);
	discr = (b * b) - (4 * c * a);
	free(cam_to_sp);
	if (discr < 0)
		return (0);
	dist_front = ((b * (-1)) + sqrt(discr)) / 2 * a;
	dist_back = ((b * (-1)) - sqrt(discr)) / 2 * a;
	if ((dist_front >= min && dist_front <= max)  && dist_front < dist)
		dist = dist_front;
	if ((dist_back >= min && dist_back <= max) && dist_back < dist)
		dist = dist_back;
	return (dist);
}