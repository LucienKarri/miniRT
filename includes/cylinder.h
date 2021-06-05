#ifndef CYLINDER_H
# define CYLINDER_H

typedef struct s_cy
{
	t_vec		*origin;
	t_vec		*nrmd;
	double		diametr;
	double		height;
	double		distance1;
	double		distance2;
	double		distance;
	double		dist;
	double		k;
	int			color;
	struct s_cy	*next;
}				t_cy;

t_cy	*cy_default(t_vec *origin, t_vec *nrmd, double t[2], int color);
int		cy_list(t_cy **cy_list, t_vec *v[2], double t[2], int color);
double	cylinder_intersection(t_vec *pos, t_vec *ray, t_cy *cy);
t_vec	*cy_norm1(t_vec *pos, t_vec *ray, t_cy *cy);

#endif