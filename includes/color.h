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
int light_color(int light, int trgb, double intensive);
int	sum_color(int trgb1, int light);

#endif