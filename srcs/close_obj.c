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
//		printf("test\n");
	//	printf("%f, %f, %f\n\n", tmp_sp->center->x, tmp_sp->center->y,
	//	 tmp_sp->center->z);
	//	tmp_sp->center = look_at(sc->cam, tmp_sp->center);
		dist_sp = sp_crossing(pos, ray, tmp_sp, min, max);
//		if (dist_sp != 0)
//			printf("test\n");
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
	float	dist_tr;
	float	c_tr = 100000;
	tmp_tr = sc->tr;
	while (tmp_tr != NULL)
	{
		dist_tr = tr_crossing(pos, ray, tmp_tr);
//		if (dist_tr > 0)
//			printf("%f\n", dist_tr);
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