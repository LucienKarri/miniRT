#include "../includes/minirt.h"

t_sp 	*sp_default(t_vec *center, float radius)
{
	t_sp 	*sp;

	sp = malloc(sizeof(t_sp));
	sp->center = center;
	sp->radius = radius;
	return (sp);
}