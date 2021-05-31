#include "../includes/minirt.h"

double 	sp_crossing(t_vec *pos, t_vec *ray, t_sp *sp)
{
	double	k[3];
	double	discr;
	double	dist;
	t_vec	*cam_to_sp;

	dist = 100000;
	cam_to_sp = vec_subtract(pos, sp->center);
	k[0] = vec_dot_product(ray, ray);
	k[1] = 2 *(vec_dot_product(cam_to_sp, ray));
	k[2] = vec_dot_product(cam_to_sp, cam_to_sp) - (sp->radius * sp->radius);
	discr = (k[1] * k[1]) - (4 * k[2] * k[0]);
	free(cam_to_sp);
	if (discr < 0)
		return (0);
	sp->dist1 = ((k[1] * (-1)) + sqrt(discr)) / (2 * k[0]);
	sp->dist2 = ((k[1] * (-1)) - sqrt(discr)) / (2 * k[0]);
	if (sp->dist1 > 0 && sp->dist1 < dist)
		dist = sp->dist1;
	if (sp->dist2 > 0 && sp->dist2 < dist)
		dist = sp->dist2;
	return (dist);
}
