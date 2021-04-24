#include "../includes/minirt.h"

t_triangle 	*tr_default(t_vec *p1, t_vec *p2, t_vec *p3)
{
	t_triangle 	*tr;

	tr = malloc(sizeof(t_triangle));
	tr->p1 = p1;
	tr->p2 = p2;
	tr->p3 = p3;
	return (tr);
}