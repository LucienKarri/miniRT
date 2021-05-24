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
