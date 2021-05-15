#include "../includes/minirt.h"

void	rotation_x(t_vec *ray, float x)
{
	t_vec	tmp;

	tmp.x = ray->x;
	tmp.y = ray->y * cos(x) - ray->z * sin(x);
	tmp.z = ray->y * sin(x) + ray->z * cos(x);
	*ray = tmp;
}

void	rotation_y(t_vec *ray, float y)
{
	t_vec	tmp;

	tmp.x = ray->x * cos(y) + ray->z * sin(y);
	tmp.y = ray->y;
	tmp.z = ray->x * -sin(y) + ray->z * cos(y);
	*ray = tmp;
}

void	rotation_z(t_vec *ray, float z)
{
	t_vec	tmp;

	tmp.x = ray->x * cos(z) - ray->y * sin(z);
	tmp.y = ray->x * sin(z) + ray->y * cos(z);
	tmp.z = ray->z;
	*ray = tmp;
}

void	rotation(t_vec *ray, t_vec *dir)
{
	rotation_x(ray, dir->x);
	rotation_y(ray, dir->y);
	rotation_z(ray, dir->z);
}
