#include "../includes/minirt.h"

t_vec	*vec_default(double x, double y, double z)
{
	t_vec	*vec;

	vec = malloc(sizeof(t_vec));
	if (!vec)
		error_and_exit(-1);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

double	vec_length(t_vec vec)
{
	double	res;

	res = sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	return (res);
}

t_vec	*vec_subtract(t_vec vec1, t_vec vec2)
{
	return (vec_default(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z));
}

t_vec	*vec_cross(t_vec vec1, t_vec vec2)
{
	return (vec_default(vec1.y * vec2.z - vec1.z * vec2.y, vec1.z * vec2.x
			- vec1.x * vec2.z, vec1.x * vec2.y - vec1.y * vec2.x));
}

void	vec_normalize(t_vec vec)
{
	double	len;

	len = vec_length(vec);
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
}
