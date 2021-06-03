#include "../includes/minirt.h"

t_pl	*pl_default(t_vec *crd, t_vec *nrmd, int color)
{
	t_pl	*pl;

	pl = malloc(sizeof(t_pl));
	if (!pl)
		error_and_exit(-1);
	pl->crd = crd;
	pl->nrmd = nrmd;
	pl->color = color;
	pl->distance = 100000;
	pl->next = NULL;
	return (pl);
}

void	pl_list(t_pl **pl_list, t_vec *crd, t_vec *nrmd, int color)
{
	t_pl	*new_pl;

	new_pl = pl_default(crd, nrmd, color);
	new_pl->next = *pl_list;
	*pl_list = new_pl;
}

t_vec	*pl_norm(t_pl *pl)
{
	t_vec	*n;

	n = vec_default(pl->nrmd->x, pl->nrmd->y, pl->nrmd->z);
	return (n);
}
