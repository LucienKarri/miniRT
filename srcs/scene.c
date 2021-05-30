#include "../includes/minirt.h"

t_sc	*sc_default(t_cam *cam, t_sp *sp, t_tr *tr, t_pl *pl, t_l *l, t_a *a)
{
	t_sc	*sc;

	sc = malloc(sizeof(t_sc));
	sc->cam = cam;
	sc->sp = sp;
	sc->tr = tr;
	sc->pl = pl;
	sc->l = l;
	sc->a = a;
	sc->width = 0;
	sc->hight = 0;
	return (sc);
}

t_sc	*empty_scene(int color)
{
	t_sc	*sc;

	sc = malloc(sizeof(t_sc));
	sc->cam = NULL;
	sc->sp = NULL;
	sc->tr = NULL;
	sc->pl = NULL;
	sc->l = NULL;
	sc->a = NULL;
	sc->sq = NULL;
	sc->width = color;
	sc->hight = 0;
	return (sc);
}
