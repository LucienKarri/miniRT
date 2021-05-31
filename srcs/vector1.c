#include "../includes/minirt.h"

double	vec_dot_product(t_vec *vec1, t_vec *vec2)
{
	double	res;

	res = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return (res);
}

t_vec	*vec_sum(t_vec *vec1, t_vec *vec2)
{
	t_vec	*res;

	res = vec_default(0, 0, 0);
	res->x = vec1->x + vec2->x;
	res->y = vec1->y + vec2->y;
	res->z = vec1->z + vec2->z;
	return (res);
}

t_vec	*vec_multiplication(t_vec *vec, double k)
{
	t_vec	*res;

	res = vec_default(0, 0, 0);
	res->x = vec->x * k;
	res->y = vec->y * k;
	res->z = vec->z * k;
	return (res);
}
