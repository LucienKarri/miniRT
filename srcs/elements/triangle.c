#include "../includes/minirt.h"

t_tr 	*tr_default(t_vec *p1, t_vec *p2, t_vec *p3, int color)
{
	t_tr	*tr;

	tr = (t_tr *)malloc(sizeof(t_tr));
	if (!tr)
		error_and_exit(-1);
	tr->p1 = p1;
	tr->p2 = p2;
	tr->p3 = p3;
	tr->color = color;
	tr->distance = 100000;
	tr->next = NULL;
	return (tr);
}

void	tr_list(t_tr **tr_list, t_vec **p, int color)
{
	t_tr	*new_tr;

	new_tr = tr_default(p[0], p[1], p[2], color);
	new_tr->next = *tr_list;
	*tr_list = new_tr;
}

t_vec	*tr_norm(t_tr *tr)
{
	t_vec	*vec[2];
	t_vec	*n;

	vec[0] = vec_subtract(tr->p2, tr->p1);
	vec[1] = vec_subtract(tr->p3, tr->p1);
	n = vec_cross(vec[0], vec[1]);
	vec_free(2, vec);
	return (n);
}
