#include "../includes/minirt.h"

t_vec	*vec_default(float x, float y, float z)
{
	t_vec	*vec;
	vec = malloc(sizeof(t_vec));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

float	vec_length(t_vec *vec)
{
	float	res;

	res = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return (res);
}

t_vec	*vec_subtract(t_vec *vec1, t_vec *vec2)
{
	t_vec	*res;

	res = vec_default(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z);
	return (res);
}

void	vec_normalize(t_vec *vec)
{
	float	len;

	len = vec_length(vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

float	vec_dot_product(t_vec *vec1, t_vec *vec2)
{
	float 	res;

	res = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return (res);
}