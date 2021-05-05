#include "../includes/minirt.h"

t_sp 	*sp_default(t_vec *center, float diameter, int color)
{
	t_sp 	*sp;

	sp =(t_sp *)malloc(sizeof(t_sp));
	sp->center = center;
	sp->radius = diameter / 2;
	sp->color = color;
	sp->distance = 0;
	sp->next = NULL;
	return (sp);
}

void 	sp_list(t_sp **sp_list, t_vec *center, float diameter, int color)
{
	t_sp	*new_sp;

	new_sp = sp_default(center, diameter, color);
	new_sp->next = *sp_list;
	*sp_list = new_sp;
}