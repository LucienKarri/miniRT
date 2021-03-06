#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct s_ray
{
	t_vec	*o;
	t_vec	*dir;
}				t_ray;

t_vec	*vec_default(double x, double y, double z);
double	vec_length(t_vec *vec);
t_vec	*vec_subtract(t_vec *vec1, t_vec *vec2);
void	vec_normalize(t_vec *vec);
double	vec_dot_product(t_vec *vec1, t_vec *vec2);
t_vec	*vec_cross(t_vec *vec1, t_vec *vec2);
t_vec	*vec_sum(t_vec *vec1, t_vec *vec2);
t_vec	*vec_multiplication(t_vec *vec, double k);
void	vec_free(int i, t_vec *vec[]);
int		vec_free_zero(int i, t_vec *vec[]);
t_vec	*cam_to_anything(t_vec *pos, t_vec *ray, double dist);

#endif