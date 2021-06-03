#include "../includes/minirt.h"

t_sq	*sq_default(t_vec *center, t_vec *nrmd, double side, int color)
{
	t_sq	*sq;

	sq = malloc(sizeof(t_sq));
	if (!sq)
		error_and_exit(-1);
	sq->center = center;
	sq->nrmd = nrmd;
	sq->side = side;
	sq->color = color;
	sq->distance = 0;
	sq->next = NULL;
	return (sq);
}

void	sq_list(t_sq **sq_list, t_vec *v[2], double side, int color)
{
	t_sq	*new_sq;

	new_sq = sq_default(v[0], v[1], side, color);
	new_sq->next = *sq_list;
	*sq_list = new_sq;
}

t_vec	*sq_norm(t_sq *sq)
{
	t_vec	*n;

	n = vec_default(sq->nrmd->x, sq->nrmd->y, sq->nrmd->z);
	return (n);
}
