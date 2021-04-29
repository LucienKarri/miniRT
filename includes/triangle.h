#ifndef TRIANGLE_H
# define TRITRIANGLE_H

typedef struct	s_triangle
{
	t_vec	*p1;
	t_vec	*p2;
	t_vec	*p3;
}				t_triangle;

t_triangle	*tr_default(t_vec *p1, t_vec *p2, t_vec *p3);
int tr_crossing(t_cam *cam, t_vec *ray, t_triangle *tr);

#endif