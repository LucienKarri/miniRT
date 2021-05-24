#include "../includes/minirt.h"

t_a	*a_default(float ratio, int color)
{
	t_a	*new_a;

	new_a = (t_a *)malloc(sizeof(t_a));
	new_a->ratio = ratio;
	new_a->color = color;
	return (new_a);
}
