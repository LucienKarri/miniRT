#ifndef MINIRT_H
# define MINIRT_H

/*standard libraries*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>

/*other libraries*/
#include "../minilibx-linux/mlx.h"

/*vector*/
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

/*sphere*/
typedef struct	s_sp
{
	t_vec	*center;
	float	radius;
}				t_sp;

t_sp 	*sp_default(t_vec *center, float radius);

/*camera*/
typedef struct 	s_cam
{
	t_vec	*pos;
	t_vec	*direction;
	float 	fov;
}				t_cam;

t_cam 	*cam_default(t_vec *pos, t_vec *direction, float fov);

/*triangle*/
typedef struct	s_triangle
{
	t_vec	*p1;
	t_vec	*p2;
	t_vec	*p3;
}				t_triangle;

t_triangle	*tr_default(t_vec *p1, t_vec *p2, t_vec *p3);
int tr_crossing(t_cam *cam, t_vec *ray, t_triangle *tr);

/*plane*/
typedef struct	s_pl
{
	t_vec	*crd;
	t_vec	*nrmd;
}				t_pl;

t_pl	*pl_default(t_vec *crd, t_vec *nrmd);
int	pl_intersection(t_cam *cam, t_vec *ray, t_pl *pl);

/*scene*/
typedef struct	s_sc
{
	t_cam	*cam;
	t_sp	*sp;
	t_triangle	*tr;
	t_pl	*pl;
	float	width;
	float	hight;
}				t_sc;

t_sc	*sc_default(t_cam *cam, t_sp *sp, t_triangle *tr, t_pl *pl);

/*view screen*/
typedef struct	s_screen
{
	float width;
	float hight;
	float screen_x;
	float screen_y;
}				t_screen;

t_screen	*screen_default(float width, float hight, float fov);

/*ray tracing*/
void	ray_tracing(void *mlx, void *window, t_sc *sc);

/*sphere crossing*/
int			sp_crossing(t_cam *cam, t_vec *ray, t_sp *sp);

#endif