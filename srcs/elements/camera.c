#include "../includes/minirt.h"

t_cam 	*cam_default(t_vec *pos, t_vec *direction, double fov)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		error_and_exit(-1);
	cam->pos = pos;
	cam->direction = direction;
	cam->fov = fov;
	cam->next = NULL;
	return (cam);
}

void 	cam_list(t_cam **cam_list, t_vec *pos, t_vec *direction, double fov)
{
	t_cam	*new_cam;

	new_cam = cam_default(pos, direction, fov);
	new_cam->next = *cam_list;
	*cam_list = new_cam;
}

t_vec	*cam_to_anything(t_vec *pos, t_vec *ray, double dist)
{
	t_vec	*vec1[2];
	t_vec	*cam_to;

	vec1[0] = vec_multiplication(ray, dist);
	vec1[1] = vec_sum(pos, vec1[0]);
	cam_to = vec_subtract(vec1[1], pos);
	vec_free(2, vec1);
	return (cam_to);
}
