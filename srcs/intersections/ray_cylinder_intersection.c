#include "../../includes/minirt.h"

int	cy_crossing(t_vec *pos, t_vec *ray, t_cy *cy, double t[2])
{
	double	k[3];
	double	discr;
	t_vec	*v;
	t_vec	*u;

	v = vec_multiplication(cy->nrmd, vec_dot_product(ray, cy->nrmd));
	v = vec_subtract(ray, v);
	u = vec_multiplication(cy->nrmd, vec_dot_product(vec_subtract(pos, cy->origin), cy->nrmd));
	u = vec_subtract(vec_subtract(pos, cy->origin), u);
	k[0] = vec_dot_product(v, v);
	k[1] = 2 * vec_dot_product(v, u);
	k[2] = vec_dot_product(u, u) - (cy->diametr * cy->diametr);
	discr = (k[1] * k[1]) - (4 * k[0] * k[2]);
	if (discr < 0)
		return (0);
	t[0] = ((k[1] * (-1)) + sqrt(discr)) / (2 * k[0]);
	t[1] = ((k[1] * (-1)) - sqrt(discr)) / (2 * k[0]);
	if (t[0] < 0 && t[1] < 0)
		return (0);
	return (1);
}

t_vec	*cy_norm(t_vec *pos, t_vec *ray, t_cy *cy, double t[2])
{
	double	dist;
	double	k;
	t_vec	*n;

	if ((cy->distance1 >= 0 && cy->distance1 <= cy->height && t[0] > 0) && (cy->distance2 >= 0 && cy->distance2 <= cy->height && t[1] > 0))
	{
		if (t[0] < t[1])
		{
			dist = cy->distance1;
			k = t[0];
		}
		else
		{
			dist = cy->distance2;
			k = t[1];
		}
	}
	else if (cy->distance1 >= 0 && cy->distance1 <= cy->height && t[0] > 0)
	{
		dist = cy->distance1;
		k = t[0];
	}
	else
	{
		dist = cy->distance2;
		k = t[1];
	}
	t[0] = k;
	n = vec_subtract(vec_subtract(vec_multiplication(ray, k), vec_multiplication(cy->nrmd, dist)), vec_subtract(cy->origin, pos));
	vec_normalize(n);
	return (n);
}

double	cy_intersect(t_vec *pos, t_vec *ray, t_cy *cy)
{
	double	t[2];

	if (cy_crossing(pos, ray, cy, t) == 0)
		return (0);
	cy->distance1 = vec_dot_product(cy->nrmd, vec_subtract(vec_multiplication(ray, t[0]), vec_subtract(cy->origin, pos)));
	cy->distance2 = vec_dot_product(cy->nrmd, vec_subtract(vec_multiplication(ray, t[1]), vec_subtract(cy->origin, pos)));
	if (!((cy->distance1 >= 0 && cy->distance1 <= cy->height && t[0] > 0 ) || (cy->distance2 >= 0 && cy->distance2 <= cy->height && t[0] > 0)))
		return (0);
	cy->li = cy_norm(pos, ray, cy, t);
	return (t[0]);
}

double	cylinder_intersection(t_vec *pos, t_vec *ray, t_cy *cy)
{
	double	point;

	point = cy_intersect(pos, ray, cy);
	if (point < 100000 && point != 0)
		return (point);
	return (0);
}
