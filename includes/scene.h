#ifndef SCENE_H
# define SCENE_H

typedef struct	s_sc
{
	t_cam	*cam;
	t_sp	*sp;
	t_tr	*tr;
	t_pl	*pl;
	t_l		*l;
	t_a		*a;
	float	width;
	float	hight;
}				t_sc;

t_sc	*sc_default(t_cam *cam, t_sp *sp, t_tr *tr, t_pl *pl, t_l *l, t_a *a);

#endif