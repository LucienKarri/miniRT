#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vec
{
	float	x;
	float 	y;
	float 	z;
}				t_vec;

t_vec	*vec_default(float x, float y, float z);
float	vec_length(t_vec *vec);
t_vec	*vec_subtract(t_vec *vec1, t_vec *vec2);
void	vec_normalize(t_vec *vec);
float	vec_dot_product(t_vec *vec1, t_vec *vec2);
t_vec	*vec_cross(t_vec *vec1, t_vec *vec2);
t_vec	*vec_sum(t_vec *vec1, t_vec *vec2);
t_vec	*vec_multiplication(t_vec *vec, float k);

#endif