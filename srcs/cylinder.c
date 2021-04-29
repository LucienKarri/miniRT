#include "../includes/minirt.h"

t_cy	*cy_default(t_vec *center, t_vec *nrmd, float diameter, float height)
{
	t_cy	*cy;

	cy = malloc(sizeof(t_cy));
	cy->center = center;
	cy->nrmd = nrmd;
	cy->diameter = diameter / 2;
	cy->height = height;
	return (cy);
}