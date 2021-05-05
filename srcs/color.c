#include "../includes/minirt.h"

int	creat_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b << 0);
}

int mul_color(int trgb, float k)
{
//	printf("%i\n", trgb);
	int	r = ((trgb & (0xFF << 16)) >> 16);
	int	g = ((trgb & (0xFF << 8)) >> 8);
	int	b = ((trgb & (0xFF << 0)) >> 0);
	r = r * k;
	g = g * k;
	b = b * k;
	return (r << 16 | g << 8 | b << 0);
}

int	color_mixer(int trgb1, int trgb2)
{
	int	r1 = (trgb1 & (0xFF << 16)) >> 16;
	int	g1 = (trgb1 & (0xFF << 8)) >> 8;
	int	b1 = (trgb1 & (0xFF << 0)) >> 0;
	int	r2 = (trgb2 & (0xFF << 16)) >> 16;
	int	g2 = (trgb2 & (0xFF << 8)) >> 8;
	int	b2 = (trgb2 & (0xFF << 0)) >> 0;
	int r = r1 * 0.5 + r2 * 0.5;
	int g = g1 * 0.5 + g2 * 0.5;
	int b = b1 * 0.5 + b2 * 0.5;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (r << 16 | g << 8 | b << 0);
}