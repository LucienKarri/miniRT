#ifndef CYLINDER_H
# define CYLINDER_H

/*cylinder*/
typedef struct	s_cy
{
	float	diameter;
	float	height;
	t_vec	*center;
	t_vec	*nrmd;
}				t_cy;

t_cy	*cy_default(t_vec *center, t_vec *nrmd, float diameter, float height);

#endif