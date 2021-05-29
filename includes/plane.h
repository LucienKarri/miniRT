#ifndef PLANE_H
# define PLANE_H

typedef struct	s_pl
{
	t_vec		*crd;
	t_vec		*nrmd;
	int			color;
	double		distance;
	struct s_pl	*next;
}				t_pl;

t_pl	*pl_default(t_vec *crd, t_vec *nrmd, int color);
void	pl_list(t_pl **pl_list, t_vec *crd, t_vec *nrmd, int color);
double	pl_intersection(t_vec *pos, t_vec *ray, t_vec *n_pl, t_vec *o_pl);

#endif