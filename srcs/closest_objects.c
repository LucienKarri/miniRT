#include "../includes/minirt.h"

t_sp	*closing_sp(t_vec *pos, t_vec *ray, t_sc *sc)
{
	t_sp	*tmp_sp;
	t_sp	*close_sp;
	double	dist_sp;
	double	c_sp;

	close_sp = NULL;
	c_sp = 100000;
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
	t_tr	*close_tr;
	double	dist_tr;
	double	c_tr;

	c_tr = 100000;
	close_tr = NULL;
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
	t_pl	*close_pl;
	t_pl	*tmp;
	double	dist_pl;
	double	c_pl;

	c_pl = 100000;
	close_pl = NULL;
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

t_sq	*closing_sq(t_vec *pos, t_vec *ray, t_sc *sc)
{
	t_sq	*close_sq;
	t_sq	*tmp;
	double	dist_sq;
	double	c_sq;

	close_sq = NULL;
	c_sq = 100000;
	tmp = sc->sq;
	while (tmp != NULL)
	{
		dist_sq = sq_intersection(pos, ray, tmp);
		if (dist_sq < c_sq && dist_sq != 0)
		{
			c_sq = dist_sq;
			close_sq = tmp;
		}
		tmp = tmp->next;
	}
	if (close_sq == NULL)
		return (0);
	close_sq->distance = c_sq;
	return (close_sq);
}

t_cy	*closing_cy(t_vec *pos, t_vec *ray, t_sc *sc)
{
	t_cy	*close_cy;
	t_cy	*tmp;
	double	dist_cy;
	double	c_cy;

	close_cy = NULL;
	c_cy = 100000;
	tmp = sc->cy;
	while (tmp != NULL)
	{
		dist_cy = cylinder_intersection(pos, ray, tmp);
		if (dist_cy < c_cy && dist_cy != 0)
		{
			c_cy = dist_cy;
			close_cy = tmp;
		}
		tmp = tmp->next;
	}
	if (close_cy == NULL)
		return (0);
	close_cy->distance = c_cy;
	return (close_cy);
}
