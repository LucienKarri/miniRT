#include "../includes/minirt.h"

t_inter	*new_inter(void)
{
	t_inter	*new;

	new = malloc(sizeof(t_inter));
	if (!new)
		error_and_exit(-1);
	new->sp = NULL;
	new->sq = NULL;
	new->pl = NULL;
	new->cy = NULL;
	new->tr = NULL;
	new->n = NULL;
	new->color = 0;
	new->dist = 100000;
	return (new);
}

int	inter_free(t_inter *inter)
{
	free(inter);
	return (0);
}
