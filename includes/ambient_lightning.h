#ifndef AMBIENT_LIGHTNING_H
# define AMBIENT_LIGHTNING_H

typedef struct	s_a
{
	float	ratio;
	int		color;
}				t_a;

t_a	*a_default(float ratio, float color);

#endif