#include "../includes/minirt.h"

t_cam 	*cam_default(t_vec *pos, t_vec *direction, float fov)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	cam->pos = pos;
	cam->direction = direction;
	cam->fov = fov;
	cam->next = NULL;
	return (cam);
}

void 	cam_list(t_cam **cam_list, t_vec *pos, t_vec *direction, float fov)
{
	t_cam	*new_cam;

	new_cam = cam_default(pos, direction, fov);
	new_cam->next = *cam_list;
	*cam_list = new_cam;
}

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
	if (dir->x == 0 && (dir->y == 1 || dir->y
	== -1) && dir->z == 0)
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
	t_vec	*dir = cam_dir(cam);
	t_vec	*right = cam_right(dir);
	t_vec	*up = cam_up(right, dir);
	float 	a[3][3];
	a[0][0] = right->x;
	a[0][1] = right->y;
	a[0][2] = right->z;
	a[1][0] = up->x;
	a[1][1] = up->y;
	a[1][2] = up->z;
	a[2][0] = dir->x;
	a[2][1] = dir->y;
	a[2][2] = dir->z;
	t_vec	*result = vec_default(0, 0, 0);
	result->x = (a[0][0] * ray->x) + (a[1][0] * ray->y) + (a[2][0] * ray->z);
	result->y = (a[0][1] * ray->x) + (a[1][1] * ray->y) + (a[2][1] * ray->z);
	result->z = (a[0][2] * ray->x) + (a[1][2] * ray->y) + (a[2][2] * ray->z);
	return (result);
}