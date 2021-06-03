#ifndef CLOSE_INTER_H
# define CLOSE_INTER_H

typedef struct s_inter
{
	t_sq	*sq;
	t_cy	*cy;
	t_sp	*sp;
	t_pl	*pl;
	t_tr	*tr;
	int		color;
	double	dist;
	t_vec	*n;
}				t_inter;

t_inter	*new_inter(void);
int		inter_free(t_inter *inter);

#endif