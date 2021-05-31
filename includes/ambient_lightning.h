#ifndef AMBIENT_LIGHTNING_H
# define AMBIENT_LIGHTNING_H

typedef struct s_a
{
	double	ratio;
	int		color;
}				t_a;

t_a	*a_default(double ratio, int color);

#endif