#include "../includes/minirt.h"

t_l		*l_default(t_vec *v_point, float ratio, int color)
{
	t_l	*l;

	l = (t_l *)malloc(sizeof(t_l));
	l->v_point = v_point;
	l->ratio = ratio;
	l->color = color;
	l->next = NULL;
	return (l);
}

void	l_list(t_l **l_list, t_vec *v_point, float ratio, int color)
{
	t_l	*new_l;

	new_l = l_default(v_point, ratio, color);
	new_l->next = *l_list;
	*l_list = new_l;
}