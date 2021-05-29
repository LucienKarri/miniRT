#include "../includes/minirt.h"

t_sp	*closing_sp(t_vec *pos, t_vec *ray, t_sc *sc)
{
	t_sp	*tmp_sp;
	t_sp	*close_sp = NULL;
	double 	dist_sp;
	double	c_sp = 100000;
	tmp_sp = sc->sp;
	while (tmp_sp != NULL)
	{
		dist_sp = sp_crossing(pos, ray, tmp_sp);
		if (dist_sp < c_sp && dist_sp != 0)
		{
			c_sp = dist_sp;
			close_sp = tmp_sp;
		}
		tmp_sp = tmp_sp->next;
	}
	if (close_sp == NULL)
		return (0);
	close_sp->distance = c_sp;
	return (close_sp);
}

t_tr	*closing_tr(t_vec *pos, t_vec *ray, t_sc *sc)
{
	t_tr	*tmp_tr;
	t_tr	*close_tr = NULL;
	double	dist_tr;
	double	c_tr = 100000;
	tmp_tr = sc->tr;
	while (tmp_tr != NULL)
	{
		dist_tr = tr_crossing(pos, ray, tmp_tr);
		if (dist_tr < c_tr && dist_tr != 0)
		{
			c_tr = dist_tr;
			close_tr = tmp_tr;
		}
		tmp_tr = tmp_tr->next;
	}
	if (close_tr == NULL)
		return (0);
	close_tr->distance = c_tr;
	return (close_tr);
}

t_pl	*closing_pl(t_vec *pos, t_vec *ray, t_sc *sc)
{
	t_pl	*close_pl = NULL;
	t_pl	*tmp;
	double	dist_pl;
	double	c_pl = 100000;
	tmp = sc->pl;
	while (tmp != NULL)
	{
		dist_pl = pl_intersection(pos, ray, tmp->nrmd, tmp->crd);
		if (dist_pl < c_pl && dist_pl != 0)
		{
			c_pl = dist_pl;
			close_pl = tmp;
		}
		tmp = tmp->next;
	}
	if (close_pl == NULL)
		return (0);
	close_pl->distance = c_pl;
	return (close_pl);
}