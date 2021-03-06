#ifndef TRIANGLE_H
# define TRIANGLE_H

typedef struct s_tr
{
	t_vec		*p1;
	t_vec		*p2;
	t_vec		*p3;
	int			color;
	double		distance;
	struct s_tr	*next;
}				t_tr;

t_tr	*tr_default(t_vec *p1, t_vec *p2, t_vec *p3, int color);
double	tr_crossing(t_vec *pos, t_vec *ray, t_tr *tr);
void	tr_list(t_tr **tr_list, t_vec **p, int color);
t_vec	*tr_norm(t_tr *tr);

#endif