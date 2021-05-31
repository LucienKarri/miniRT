#include "../includes/minirt.h"

t_sc	*empty_scene(int color)
{
	t_sc	*sc;

	sc = malloc(sizeof(t_sc));
	if (!sc)
		error_and_exit(-1);
	sc->cam = NULL;
	sc->sp = NULL;
	sc->tr = NULL;
	sc->pl = NULL;
	sc->l = NULL;
	sc->a = NULL;
	sc->sq = NULL;
	sc->cy = NULL;
	sc->width = color;
	sc->hight = 0;
	return (sc);
}
