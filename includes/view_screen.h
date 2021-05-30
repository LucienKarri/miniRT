#ifndef VIEW_SCREEN_H
# define VIVIEW_SCREEN_H

typedef struct	s_screen
{
	double width;
	double hight;
	double screen_x;
	double screen_y;
}				t_screen;

t_screen	*screen_default(double width, double hight, double fov);

#endif