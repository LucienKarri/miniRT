#include "../includes/minirt.h"

int	pl_intersection(t_cam *cam, t_vec *ray, t_pl *pl)
{
	float den;
	float t;
	t_vec	*cam_to_pl;

	den = vec_dot_product(pl->nrmd, ray);
	if (den > 0.000001)
	{
		cam_to_pl = vec_subtract(pl->crd, cam->pos);
		t = vec_dot_product(cam_to_pl, pl->nrmd) / den;
		if (t >= 0)
			return (1);
	}
	return (0);
}