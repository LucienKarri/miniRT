#include "../includes/minirt.h"

t_screen	*screen_default(float width, float hight, float fov)
{
	t_screen	*screen;
	float		ratio;

	screen = malloc(sizeof(t_screen));
	ratio = width / hight;
	screen->width = tan(fov / 2 * (M_PI / 180));
	screen->width *= 2;
	screen->hight = screen->width / ratio;
	screen->screen_x = screen->width / width;
	screen->screen_y = screen->hight / hight;
	return (screen);
}