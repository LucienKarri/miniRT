#ifndef LIGHT_H
# define LIGHT_H

typedef struct	s_l
{
	float		ratio;
	t_vec		*v_point;
	int			color;
	struct s_l	*next;
}				t_l;

t_l		*l_default(t_vec *v_point, float ratio, int color);
void	l_list(t_l **l_list, t_vec *v_point, float ratio, int color);

#endif