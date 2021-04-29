#ifndef CAMERA_H
# define CACAMERA_H

typedef struct 	s_cam
{
	t_vec	*pos;
	t_vec	*direction;
	float 	fov;
}				t_cam;

t_cam 	*cam_default(t_vec *pos, t_vec *direction, float fov);

#endif