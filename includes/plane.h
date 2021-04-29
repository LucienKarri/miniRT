#ifndef PLANE_H
# define PLANE_H

typedef struct	s_pl
{
	t_vec	*crd;
	t_vec	*nrmd;
}				t_pl;

t_pl	*pl_default(t_vec *crd, t_vec *nrmd);
int	pl_intersection(t_cam *cam, t_vec *ray, t_pl *pl);

#endif