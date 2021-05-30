#ifndef SQUARE_H
# define SQUARE_H

typedef struct	s_sq
{
	t_vec		*center;
	t_vec		*nrmd;
	double		side;
	int			color;
	double		distance;
	struct s_sq	*next;
}				t_sq;

t_sq	*sq_default(t_vec *center, t_vec *nrmd, double side, int color);
void	sq_list(t_sq **sq_list, t_vec *center, t_vec *nrmd, double side, int
color);
double	sq_intersection(t_vec *pos, t_vec *ray, t_sq *sq);

#endif