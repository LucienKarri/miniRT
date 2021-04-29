#ifndef VIEW_SCREEN_H
# define VIVIEW_SCREEN_H

typedef struct	s_screen
{
	float width;
	float hight;
	float screen_x;
	float screen_y;
}				t_screen;

t_screen	*screen_default(float width, float hight, float fov);

#endif