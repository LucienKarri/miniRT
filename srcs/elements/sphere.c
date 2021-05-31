#include "../includes/minirt.h"

t_sp 	*sp_default(t_vec *center, double diameter, int color)
{
	t_sp	*sp;

	sp = malloc(sizeof(t_sp));
	if (!sp)
		error_and_exit(-1);
	sp->center = center;
	sp->radius = diameter / 2;
	sp->color = color;
	sp->distance = 0;
	sp->dist1 = 0;
	sp->dist2 = 0;
	sp->next = NULL;
	return (sp);
}

void 	sp_list(t_sp **sp_list, t_vec *center, double diameter, int color)
{
	t_sp	*new_sp;

	new_sp = sp_default(center, diameter, color);
	new_sp->next = *sp_list;
	*sp_list = new_sp;
}
