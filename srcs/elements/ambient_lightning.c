#include "../includes/minirt.h"

t_a	*a_default(float ratio, int color)
{
	t_a	*new_a;

	new_a = malloc(sizeof(t_a));
	if (!new_a)
		error_and_exit(-1);
	new_a->ratio = ratio;
	new_a->color = color;
	return (new_a);
}
