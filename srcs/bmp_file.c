#include "../includes/minirt.h"

void	bmp_header(t_all *all, int fd)
{
	unsigned int	size;
	unsigned char	*header;

	header = (unsigned char *)calloc(14, sizeof(unsigned char));
	size = 54 + (all->data->b_p_p / 8 * all->sc->width)
		* all->sc->hight;
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(size);
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
	free(header);
}

void	bmp_info(t_all *all, int fd)
{
	unsigned char	*info;
	unsigned int	hight;
	unsigned int	width;

	width = all->sc->width;
	hight = all->sc->hight;
	info = (unsigned char *)calloc(40, sizeof(unsigned char));
	info[0] = (unsigned char)(40);
	info[4] = (unsigned char)(width);
	info[5] = (unsigned char)(width >> 8);
	info[6] = (unsigned char)(width >> 16);
	info[7] = (unsigned char)(width >> 24);
	info[8] = (unsigned char)(hight);
	info[9] = (unsigned char)(hight >> 8);
	info[10] = (unsigned char)(hight >> 16);
	info[11] = (unsigned char)(hight >> 24);
	info[12] = (unsigned char)(1);
	info[14] = (unsigned char)(all->data->b_p_p);
	write(fd, info, 40);
	free(info);
}

void	bmp_file(t_all *all)
{
	int				fd;
	int				x;
	int				y;
	unsigned int	*adress;

	y = all->sc->hight - 1;
	fd = open("screen.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd > 1)
	{
		bmp_header(all, fd);
		bmp_info(all, fd);
		while (y >= 0)
		{
			x = 0;
			while (x < all->sc->width)
			{
				adress = (unsigned int *)(all->data->addr + all->data->line_len
						* y + (all->data->b_p_p / 8) * x);
				write(fd, adress, 4);
				x++;
			}
			y--;
		}
	}
	close(fd);
}
