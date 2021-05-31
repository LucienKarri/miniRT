#include "../../includes/minirt.h"

t_cy	*cy_default(t_vec *v[2], double t[2], int color)
{
	t_cy	*new_cy;

	new_cy = malloc(sizeof(t_cy));
	if (!new_cy)
		error_and_exit(-1);
	new_cy->origin = v[0];
	new_cy->nrmd = v[1];
	new_cy->diametr = t[0] / 2;
	new_cy->height = t[1];
	new_cy->color = color;
	new_cy->distance1 = 0;
	new_cy->distance2 = 0;
	new_cy->distance = 0;
	new_cy->li = NULL;
	new_cy->next = NULL;
	return (new_cy);
}

void	cy_list(t_cy **cy_list, t_vec *v[2], double t[2], int color)
{
	t_cy	*new_cy;

	new_cy = cy_default(v, t, color);
	new_cy->next = *cy_list;
	*cy_list = new_cy;
}
