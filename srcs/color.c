#include "../includes/minirt.h"

int	creat_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b << 0);
}

int light_color(int light, int trgb, double intensive)
{
	int	r = ((trgb & (0xFF << 16)) >> 16);
	int	g = ((trgb & (0xFF << 8)) >> 8);
	int	b = ((trgb & (0xFF << 0)) >> 0);
	int	lr = ((light & (0xFF << 16)) >> 16);
	int	lg = ((light & (0xFF << 8)) >> 8);
	int	lb = ((light & (0xFF << 0)) >> 0);
	lr += r * intensive;
	lg += g * intensive;
	lb += b * intensive;
	if (lr > 255)
		lr = 255;
	if (lg > 255)
		lg = 255;
	if (lb > 255)
		lb = 255;
	return (lr << 16 | lg << 8 | lb << 0);
}

int	sum_color(int trgb1, int light)
{
	int	r1 = (trgb1 & (0xFF << 16)) >> 16;
	int	g1 = (trgb1 & (0xFF << 8)) >> 8;
	int	b1 = (trgb1 & (0xFF << 0)) >> 0;
	int	lr = (light & (0xFF << 16)) >> 16;
	int	lg = (light & (0xFF << 8)) >> 8;
	int	lb = (light & (0xFF << 0)) >> 0;
	int r = r1 * lr / 255;
	int g = g1 * lg / 255;
	int b = b1 * lb / 255;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (r << 16 | g << 8 | b << 0);
}