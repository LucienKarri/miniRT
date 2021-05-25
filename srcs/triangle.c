#include "../includes/minirt.h"

t_tr 	*tr_default(t_vec *p1, t_vec *p2, t_vec *p3, int color)
{
	t_tr 	*tr;

	tr = (t_tr *)malloc(sizeof(t_tr));
	tr->p1 = p1;
	tr->p2 = p2;
	tr->p3 = p3;
	tr->color = color;
	tr->distance = 100000;
	tr->next = NULL;
	return (tr);
}

void	tr_list(t_tr **tr_list, t_vec *p1, t_vec *p2, t_vec *p3, int color)
{
	t_tr	*new_tr;

	new_tr = tr_default(p1, p2, p3, color);
	new_tr->next = *tr_list;
	*tr_list = new_tr;
}