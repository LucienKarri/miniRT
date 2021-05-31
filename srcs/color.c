#include "../includes/minirt.h"

int	creat_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b << 0);
}

int	light_color(int light, int trgb, double intensive)
{
	int	rgb[3];
	int	lrgb[3];

	rgb[0] = ((trgb & (0xFF << 16)) >> 16);
	rgb[1] = ((trgb & (0xFF << 8)) >> 8);
	rgb[2] = ((trgb & (0xFF << 0)) >> 0);
	lrgb[0] = ((light & (0xFF << 16)) >> 16);
	lrgb[1] = ((light & (0xFF << 8)) >> 8);
	lrgb[2] = ((light & (0xFF << 0)) >> 0);
	lrgb[0] += rgb[0] * intensive;
	lrgb[1] += rgb[1] * intensive;
	lrgb[2] += rgb[2] * intensive;
	if (lrgb[0] > 255)
		lrgb[0] = 255;
	if (lrgb[1] > 255)
		lrgb[1] = 255;
	if (lrgb[2] > 255)
		lrgb[2] = 255;
	return (lrgb[0] << 16 | lrgb[1] << 8 | lrgb[2] << 0);
}

int	sum_color(int trgb1, int light)
{
	int	rgb1[3];
	int	rgb[3];
	int	lrgb[3];

	rgb1[0] = (trgb1 & (0xFF << 16)) >> 16;
	rgb1[1] = (trgb1 & (0xFF << 8)) >> 8;
	rgb1[2] = (trgb1 & (0xFF << 0)) >> 0;
	lrgb[0] = (light & (0xFF << 16)) >> 16;
	lrgb[1] = (light & (0xFF << 8)) >> 8;
	lrgb[2] = (light & (0xFF << 0)) >> 0;
	rgb[0] = rgb1[0] * lrgb[0] / 255;
	rgb[1] = rgb1[1] * lrgb[1] / 255;
	rgb[2] = rgb1[2] * lrgb[2] / 255;
	if (rgb[0] > 255)
		rgb[0] = 255;
	if (rgb[1] > 255)
		rgb[1] = 255;
	if (rgb[2] > 255)
		rgb[2] = 255;
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2] << 0);
}
