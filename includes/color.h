#ifndef COLOR_H
# define COLOR_H

typedef struct	s_color
{
	int t;
	int	r;
	int g;
	int b;
}				t_color;

int	creat_color(int r, int g, int b);
int mul_color(int trgb, float k);
int	color_mixer(int trgb1, int trgb2);

#endif