#include "../includes/minirt.h"

int		main()
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();

	t_sp	*sps;
	t_vec	*sp_center1 = vec_default(0, 0, 5);
	t_vec	*sp_center2 = vec_default(-2, 2, 7);
	t_vec	*sp_center3 = vec_default(0, 4, 9);
	t_vec	*sp_center4 = vec_default(2, 6, 7);
	int 	color_sp1 = creat_color(0, 255, 255);
	int 	color_sp2 = creat_color(0, 0, 255);
	int 	color_sp3 = creat_color(255, 0, 255);
	int 	color_sp4 = creat_color(0, 255, 0);
	sp_list(&sps, sp_center1, 2, color_sp1);
	sp_list(&sps, sp_center2, 2, color_sp2);
	sp_list(&sps, sp_center3, 2, color_sp3);
	sp_list(&sps, sp_center4, 2, color_sp4);

	t_tr	*trs = NULL;
//	t_vec	*tr1_p1 = vec_default(-2, 0, 4);
//	t_vec	*tr1_p2 = vec_default(3, 1, 4);
//	t_vec	*tr1_p3 = vec_default(0, 3, 8);
//	int		color_tr1 = creat_color(120, 55, 255);
//	t_vec	*tr2_p1 = vec_default(-3, 1, 10);
//	t_vec	*tr2_p2 = vec_default(2, 0, 1);
//	t_vec	*tr2_p3 = vec_default(2, -1, 4);
//	int		color_tr2 = creat_color(255, 250, 130);
//	t_vec	*tr3_p1 = vec_default(-2, 0, -11);
//	t_vec	*tr3_p2 = vec_default(5, 0, -13);
//	t_vec	*tr3_p3 = vec_default(-2, 7, -11);
//	int 	color_tr3 = creat_color(100, 213, 50);
//	tr_list(&trs, tr1_p1, tr1_p2, tr1_p3, color_tr1);
//	tr_list(&trs, tr2_p1, tr2_p2, tr2_p3, color_tr2);
//	tr_list(&trs, tr3_p1, tr3_p2, tr3_p3, color_tr3);

	t_l		*l = NULL;
	//t_vec	*v_p = vec_default(10, 20, 10);
//	int		color_l1 = creat_color(255, 255, 255);
//	int		color_l2 = creat_color(255, 255, 255);
//	int		color_l3 = creat_color(255, 255, 255);
//	t_vec	*v_p1 = vec_default(0, 20, -6);
//	t_vec	*v_p2 = vec_default(0, 20, -10);
//	l_list(&l, v_p, 0.7, color_l1);
//	l_list(&l, v_p1, 0.7, color_l2);
//	l_list(&l, v_p2, 0.7, color_l3);

	int		color_a = creat_color(255, 0, 0);
	t_a		*a = a_default(0.3, color_a);

	t_vec 	*pl_c = vec_default(0, 0, 0);
	t_vec	*pl_n = vec_default(0, -1, 0);
	t_pl	*pl = pl_default(pl_c, pl_n);
	t_vec	*cam_pos = vec_default(0, 4, -5);
	t_vec	*cam_direction = vec_default(0, 0, 1);
	t_cam	*cam = cam_default(cam_pos, cam_direction, 60);
	t_sc	*sc = sc_default(cam, sps, trs, pl, l, a);
	sc->width = 900;
	sc->hight = 980;
	window = mlx_new_window(mlx, sc->width, sc->hight, "GOLOD");
	ray_tracing(mlx, window, sc);
	printf("READY!\n");
	mlx_loop(mlx);
	return (0);
}