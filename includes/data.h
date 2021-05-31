#ifndef DATA_H
# define DATA_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		b_p_p;
	int		line_len;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif