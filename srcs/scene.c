#include "../includes/minirt.h"

t_sc	*sc_default(t_cam *cam, t_sp *sp)
{
	t_sc	*sc;

	sc = malloc(sizeof(t_sc));
	sc->cam = cam;
	sc->sp = sp;
	sc->width = 0;
	sc->hight = 0;
	return (sc);
}