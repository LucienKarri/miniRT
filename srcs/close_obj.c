#include "../includes/minirt.h"

t_sp	*closing_sp(t_vec *pos, t_vec *ray, t_sc *sc, float min, float max)
{
	t_sp	*tmp_sp;
	t_sp	*close_sp = NULL;
	float 	dist_sp;
	float	c_sp = 100000;
	tmp_sp = sc->sp;
	while (tmp_sp != NULL)
	{
		dist_sp = sp_crossing(pos, ray, tmp_sp, min, max);
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

/*close_tr()
{
	while (tmp_tr != NULL)
	{
		dist_tr = tr_crossing(scene->cam, ray, tmp_tr);
		if (dist_tr < c_tr && dist_tr != 0)
		{
			c_tr = dist_tr;
			close_tr = tmp_tr;
		}
		tmp_tr = tmp_tr->next;
	}
}*/