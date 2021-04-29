#include "../includes/minirt.h"

int		main()
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();

	t_sp	*sps;
	t_vec	*sp_center1 = vec_default(0, 0, -15);
	t_vec	*sp_center2 = vec_default(0, 0, -12);
	sp_list(&sps, sp_center1, 2, 12345);
	sp_list(&sps, sp_center2, 1, 24686);

	t_tr	*trs;
	t_vec	*tr1_p1 = vec_default(-2, 0, -11);
	t_vec	*tr1_p2 = vec_default(5, 0, -13);
	t_vec	*tr1_p3 = vec_default(-2, 7, -11);
	t_vec	*tr2_p1 = vec_default(-5, 0, -13);
	t_vec	*tr2_p2 = vec_default(2, 0, -11);
	t_vec	*tr2_p3 = vec_default(2, 7, -11);
	tr_list(&trs, tr1_p1, tr1_p2, tr1_p3, 90000);
	tr_list(&trs, tr2_p1, tr2_p2, tr2_p3, 75000);

	t_vec 	*pl_c = vec_default(0, 0, 0);
	t_vec	*pl_n = vec_default(0, -1, 0);
	t_pl	*pl = pl_default(pl_c, pl_n);
	t_vec	*cam_pos = vec_default(0, 0, 0);
	t_vec	*cam_direction = vec_default(0, 0, -1);
	t_cam	*cam = cam_default(cam_pos, cam_direction, 70);
	t_sc	*sc = sc_default(cam, sps, trs, pl);
	sc->width = 720;
	sc->hight = 480;
	window = mlx_new_window(mlx, sc->width, sc->hight, "GOLOD");
	ray_tracing(mlx, window, sc);
	mlx_loop(mlx);
	return (0);
}