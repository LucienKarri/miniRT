#include "../includes/minirt.h"

int	sp_crossing(t_cam *cam, t_vec *ray, t_sp *sp)
{
	float b;
	float c;
	float discr;
	float dist_front = 0;
//	float dist_back = 0;
	t_vec	*cam_to_sp;

	cam_to_sp = vec_subtract(cam->pos, sp->center);
	b = 2 *(vec_dot_product(cam_to_sp, ray));
	c = vec_dot_product(cam_to_sp, cam_to_sp) - (sp->radius * sp->radius);
	discr = (b * b) - (4 * c);
	free(cam_to_sp);
	if (discr < 0)
		return (0);
	dist_front = ((b * (-1)) - sqrt(discr)) / 2;
//	dist_back = ((b * (-1)) + sqrt(discr)) / 2;
	if (dist_front > 0)
		return (1);
	return (0);
}