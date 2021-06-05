#include "../includes/minirt.h"

double	vec_dot_product(t_vec *vec1, t_vec *vec2)
{
	double	res;

	res = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return (res);
}

t_vec	*vec_sum(t_vec *vec1, t_vec *vec2)
{
	return (vec_default(vec1->x + vec2->x,
			vec1->y + vec2->y, vec1->z + vec2->z));
}

t_vec	*vec_multiplication(t_vec *vec, double k)
{
	return (vec_default(vec->x * k, vec->y * k, vec->z * k));
}

void	vec_free(int i, t_vec *vec[])
{
	while (i-- && i >= 0)
	{
		if (vec[i])
			free(vec[i]);
	}
}

int	vec_free_zero(int i, t_vec *vec[])
{
	while (i-- && i >= 0)
	{
		if (vec[i])
			free(vec[i]);
	}
	return (0);
}
