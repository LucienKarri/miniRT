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
		up = vec_default(0, 0, 1);
	else
		up = vec_default(0, 1, 0);
	res = vec_cross(up, dir);
	vec_normalize(res);
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
	t_vec	*right;
	t_vec	*up;
	t_vec	*result;
	double	a[3][3];

	dir = cam_dir(cam);
	right = cam_right(dir);
	up = cam_up(right, dir);
	a[0][0] = right->x;
	a[0][1] = right->y;
	a[0][2] = right->z;
	a[1][0] = up->x;
	a[1][1] = up->y;
	a[1][2] = up->z;
	a[2][0] = dir->x;
	a[2][1] = dir->y;
	a[2][2] = dir->z;
	result = vec_default(0, 0, 0);
	result->x = (a[0][0] * ray->x) + (a[1][0] * ray->y) + (a[2][0] * ray->z);
	result->y = (a[0][1] * ray->x) + (a[1][1] * ray->y) + (a[2][1] * ray->z);
	result->z = (a[0][2] * ray->x) + (a[1][2] * ray->y) + (a[2][2] * ray->z);
	return (result);
}
