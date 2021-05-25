#ifndef ALL_H
# define ALL_H

typedef struct	s_all
{
	t_sc	*sc;
	t_data	*data;
	void	*mlx;
	void	*win;
}				t_all;

t_all	*all_default(t_sc *sc, t_data *img);

#endif