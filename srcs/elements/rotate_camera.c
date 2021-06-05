#include "../includes/minirt.h"

t_vec	*cam_dir(t_cam *cam)
{
	t_vec	*res;

	res = cam->direction;
	vec_normalize(res);
	return (res);
}

t_vec	*cam_right(t_vec *dir)
{
	t_vec	*up;
	t_vec	*res;

	if (dir->x == 0 && (dir->y == 1 || dir->y == -1) && dir->z == 0)
		up = vec_default(1, 0, 0);
	else
		up = vec_default(0, 1, 0);
	res = vec_cross(up, dir);
	vec_normalize(res);
	free(up);
	return (res);
}

t_vec	*cam_up(t_vec *right, t_vec *dir)
{
	t_vec	*res;

	res = vec_cross(dir, right);
	return (res);
}

t_vec	*look_at(t_cam *cam, t_vec *ray)
{
	t_vec	*dir;
	t_vec	*ur[2];
	t_vec	*result;
	double	a[3][3];

	dir = cam_dir(cam);
	ur[1] = cam_right(dir);
	ur[0] = cam_up(ur[1], dir);
	vec_normalize(ray);
	a[0][0] = ur[1]->x;
	a[0][1] = ur[1]->y;
	a[0][2] = ur[1]->z;
	a[1][0] = ur[0]->x;
	a[1][1] = ur[0]->y;
	a[1][2] = ur[0]->z;
	a[2][0] = dir->x;
	a[2][1] = dir->y;
	a[2][2] = dir->z;
	result = vec_default(0, 0, 0);
	result->x = (a[0][0] * ray->x) + (a[1][0] * ray->y) + (a[2][0] * ray->z);
	result->y = (a[0][1] * ray->x) + (a[1][1] * ray->y) + (a[2][1] * ray->z);
	result->z = (a[0][2] * ray->x) + (a[1][2] * ray->y) + (a[2][2] * ray->z);
	vec_free(2, ur);
	vec_normalize(result);
	return (result);
}
