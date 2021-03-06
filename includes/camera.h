#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_cam
{
	t_vec			*pos;
	t_vec			*direction;
	double			fov;
	struct s_cam	*next;
}				t_cam;

t_cam	*cam_default(t_vec *pos, t_vec *direction, double fov);
void	cam_list(t_cam **cam_list, t_vec *pos, t_vec *direction, double fov);
t_vec	*cam_dir(t_cam *cam);
t_vec	*cam_up(t_vec *right, t_vec *dir);
t_vec	*cam_right(t_vec *dir);
t_vec	*look_at(t_cam *cam, t_vec *ray);

#endif