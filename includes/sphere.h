#ifndef SPHERE_H
# define SPHERE_H

typedef struct	s_sp
{
	t_vec		*center;
	float		radius;
	int			color;
	struct s_sp	*next;
}				t_sp;

t_sp 	*sp_default(t_vec *center, float diameter, int color);
void 	sp_list(t_sp **sp_list, t_vec *center, float diameter, int color);
float	sp_crossing(t_cam *cam, t_vec *ray, t_sp *sp);

#endif