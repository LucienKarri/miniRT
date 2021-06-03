#ifndef SPHERE_H
# define SPHERE_H

typedef struct s_sp
{
	t_vec		*center;
	double		radius;
	int			color;
	double		distance;
	double		dist1;
	double		dist2;
	struct s_sp	*next;
}				t_sp;

t_sp	*sp_default(t_vec *center, double diameter, int color);
void	sp_list(t_sp **sp_list, t_vec *center, double diameter, int color);
double	sp_crossing(t_vec *pos, t_vec *ray, t_sp *sp);
t_vec	*sp_norm(t_vec *pos, t_vec *ray, t_sp *sp, double dist);

#endif