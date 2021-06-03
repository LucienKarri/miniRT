#include "../../includes/minirt.h"

int	cy_crossing(t_vec *pos, t_vec *ray, t_cy *cy, double t[2])
{
	double	k[3];
	double	discr;
	t_vec	*tmp[5];

	tmp[0] = vec_multiplication(*cy->nrmd, vec_dot_product(*ray, *cy->nrmd));
	tmp[1] = vec_subtract(*ray, *tmp[0]);
	tmp[2] = vec_subtract(*pos, *cy->origin);
	tmp[3] = vec_multiplication(*cy->nrmd, vec_dot_product(*tmp[2], *cy->nrmd));
	tmp[4] = vec_subtract(*tmp[2], *tmp[3]);
	k[0] = vec_dot_product(*tmp[1], *tmp[1]);
	k[1] = 2 * vec_dot_product(*tmp[1], *tmp[4]);
	k[2] = vec_dot_product(*tmp[4], *tmp[4]) - (cy->diametr * cy->diametr);
	vec_free(5, tmp);
	discr = (k[1] * k[1]) - (4 * k[0] * k[2]);
	if (discr < 0)
		return (0);
	t[0] = ((k[1] * (-1)) + sqrt(discr)) / (2 * k[0]);
	t[1] = ((k[1] * (-1)) - sqrt(discr)) / (2 * k[0]);
	if (t[0] < 0 && t[1] < 0)
		return (0);
	return (1);
}

void	cy_norm(t_cy *cy, double t[2])
{
	if ((cy->distance1 >= 0 && cy->distance1 <= cy->height
			&& t[0] > 0) && (cy->distance2 >= 0
			&& cy->distance2 <= cy->height && t[1] > 0))
	{
		if (t[0] < t[1])
		{
			cy->dist = cy->distance1;
			cy->k = t[0];
		}
		else
		{
			cy->dist = cy->distance2;
			cy->k = t[1];
		}
	}
	else if (cy->distance1 >= 0 && cy->distance1 <= cy->height && t[0] > 0)
	{
		cy->dist = cy->distance1;
		cy->k = t[0];
	}
	else
	{
		cy->dist = cy->distance2;
		cy->k = t[1];
	}
}

t_vec	*cy_norm1(t_vec *pos, t_vec *ray, t_cy *cy)
{
	t_vec	*vec[5];
	t_vec	*n;

	vec[0] = vec_multiplication(*ray, cy->k);
	vec[1] = vec_multiplication(*cy->nrmd, cy->dist);
	vec[2] = vec_subtract(*cy->origin, *pos);
	vec[3] = vec_subtract(*vec[0], *vec[1]);
	vec[4] = vec_subtract(*vec[3], *vec[2]);
	n = vec_default(vec[4]->x, vec[4]->y, vec[4]->z);
	vec_normalize(*n);
	vec_free(5, vec);
	return (n);
}

double	cy_intersect(t_vec *pos, t_vec *ray, t_cy *cy)
{
	double	t[2];
	t_vec	*vec[5];

	if (cy_crossing(pos, ray, cy, t) == 0)
		return (0);
	vec[0] = vec_subtract(*cy->origin, *pos);
	vec[1] = vec_multiplication(*ray, t[0]);
	vec[2] = vec_multiplication(*ray, t[1]);
	vec[3] = vec_subtract(*vec[1], *vec[0]);
	vec[4] = vec_subtract(*vec[2], *vec[0]);
	cy->distance1 = vec_dot_product(*cy->nrmd, *vec[3]);
	cy->distance2 = vec_dot_product(*cy->nrmd, *vec[4]);
	vec_free(5, vec);
	if (!((cy->distance1 >= 0 && cy->distance1 <= cy->height
				&& t[0] > 0 ) || (cy->distance2 >= 0
				&& cy->distance2 <= cy->height && t[0] > 0)))
		return (0);
	cy_norm(cy, t);
	return (cy->k);
}

double	cylinder_intersection(t_vec *pos, t_vec *ray, t_cy *cy)
{
	double	point;

	point = cy_intersect(pos, ray, cy);
	if (point < 100000 && point != 0)
		return (point);
	return (0);
}
