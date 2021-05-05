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
	t_vec	*pos = vec_multiplication(cam->pos, -1);
	t_vec	*temp;
	float 	a[4][4];
	int		i = 0;
	int		j;
	t_vec	*result = vec_default(0, 0, 0);
	while (i < 4)
	{
		j = 0;
		if (i == 0)
			temp = right;
		if (i == 1)
			temp = up;
		if (i == 2)
			temp = dir;
		if (i == 3)
			temp = vec_default(0, 0, 0);
		while (j < 4)
		{
			if (j == 0)
				a[i][j] = (temp->x * 1) + (temp->y * 0) +
						(temp->z * 0) + (0 * 0);
			if (j == 1)
				a[i][j] = (temp->x * 0) + (temp->y * 1) +
						(temp->z * 0) + (0 * 0);
			if (j == 2)
				a[i][j] = (temp->x * 0) + (temp->y * 0) +
						(temp->z * 1) + (0 * 0);
			if (j == 3)
			{
				if (i == 3)
					a[i][j] = (temp->x * pos->x) + (temp->y * pos->y) +
							  (temp->z * pos->z) + (1 * 1);
				else
					a[i][j] = (temp->x * pos->x) + (temp->y * pos->y) +
						  (temp->z * pos->z) + (0 * 1);
			}
			j++;
		}
		i++;
	}
	result->x = (a[0][0] * ray->x) + (a[0][1] * ray->y) + (a[0][2] * ray->z)
			+ (a[0][3] * 1);
	result->y = (a[1][0] * ray->x) + (a[1][1] * ray->y) + (a[1][2] * ray->z)
			+  (a[1][3] * 1);
	result->z = (a[2][0] * ray->x) + (a[2][1] * ray->y) + (a[2][2] * ray->z)
			+  (a[2][3] * 1);
//	printf("%f, %f, %f\n", ray->x, ray->y, ray->z);
//	printf("%f, %f, %f\n\n", result->x, result->y, result->z);
	return (result);
}