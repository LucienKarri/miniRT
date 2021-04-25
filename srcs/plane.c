#include "../includes/minirt.h"

t_pl	*pl_default(t_vec *crd, t_vec *nrmd)
{
	t_pl	*pl;

	pl = malloc(sizeof(t_pl));
	pl->crd = crd;
	pl->nrmd = nrmd;
	return (pl);
}