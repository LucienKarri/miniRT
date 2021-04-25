#include "../includes/minirt.h"

int		main()
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	t_vec	*sp_center = vec_default(3, 2, -25);
	t_sp	*sp = sp_default(sp_center, 12/2);
	t_vec	*tr_p1 = vec_default(-9, -8, -20);
	t_vec	*tr_p2 = vec_default(-5, -2, -25);
	t_vec	*tr_p3 = vec_default(-3, -6, -18);
	t_triangle *tr = tr_default(tr_p1, tr_p2, tr_p3);
	t_vec 	*pl_c = vec_default(0, 0, 0);
	t_vec	*pl_n = vec_default(0, -1, 0);
	t_pl	*pl = pl_default(pl_c, pl_n);
	t_vec	*cam_pos = vec_default(0, 0, 0);
	t_vec	*cam_direction = vec_default(0, 0, -1);
	t_cam	*cam = cam_default(cam_pos, cam_direction, 70);
	t_sc	*sc = sc_default(cam, sp, tr, pl);
	sc->width = 1920;
	sc->hight = 1080;
	window = mlx_new_window(mlx, sc->width, sc->hight, "GOLOD");
	ray_tracing(mlx, window, sc);
	mlx_loop(mlx);
	return (0);
}