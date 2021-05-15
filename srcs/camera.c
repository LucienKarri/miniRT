#include "../includes/minirt.h"

t_cam 	*cam_default(t_vec *pos, t_vec *direction, float fov)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	cam->pos = pos;
	cam->direction = direction;
	cam->fov = fov;
	return (cam);
}

t_vec	*cam_dir(t_cam *cam)
{
	t_vec	*res;
	res = cam->direction;
	vec_normalize(res);
	return (res);
}

t_vec	*cam_right(t_cam *cam)
{
	t_vec	*up;
	t_vec	*res;
	if (cam->direction->x == 0 && (cam->direction->y == 1 || cam->direction->y
	== -1) && cam->direction->z == 0)
		up = vec_default(0, 0, 1);
	else
		up = vec_default(0, 1, 0);
	res = vec_cross(up, cam_dir(cam));
	vec_normalize(res);
	return (res);
}

t_vec	*cam_up(t_cam *cam)
{
	t_vec	*res;

	res = vec_cross(cam_dir(cam), cam_right(cam));
	return (res);
}

t_vec	*look_at(t_cam *cam, t_vec *ray)
{
	t_vec	*right = cam_right(cam);
	t_vec	*up = cam_up(cam);
	t_vec	*dir = cam_dir(cam);
	t_vec	*temp;
	float 	a[3][3];
	int		i = 0;
	int		j;
	t_vec	*result = vec_default(0, 0, 0);
	while (i < 3)
	{
		j = 0;
		if (i == 0)
			temp = right;
		if (i == 1)
			temp = up;
		if (i == 2)
			temp = dir;
		while (j < 3)
		{
			if (j == 0)
				a[i][j] = temp->x;
			if (j == 1)
				a[i][j] = temp->y;
			if (j == 2)
				a[i][j] = temp->z;
			j++;
		}
		i++;
	}
	result->x = (a[0][0] * ray->x) + (a[1][0] * ray->y) + (a[2][0] * ray->z);
	result->y = (a[0][1] * ray->x) + (a[1][1] * ray->y) + (a[2][1] * ray->z);
	result->z = (a[0][2] * ray->x) + (a[1][2] * ray->y) + (a[2][2] * ray->z);
//	printf("%f, %f, %f\n", ray->x, ray->y, ray->z);
//	printf("%f, %f, %f\n\n", result->x, result->y, result->z);
	return (result);
}