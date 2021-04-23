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