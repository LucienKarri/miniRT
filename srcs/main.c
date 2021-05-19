#include "../includes/minirt.h"

int		main()
{
	void	*mlx;
	void	*window;
	t_data	img;

	mlx = mlx_init();

	t_sp	*sps = NULL;
	t_vec	*sp_center1 = vec_default(0, 0, 5);
	t_vec	*sp_center2 = vec_default(-2, 2, 7);
	t_vec	*sp_center3 = vec_default(0, 4, 9);
	t_vec	*sp_center4 = vec_default(2, 6, 7);
	t_vec	*sp_center5 = vec_default(-4, -2, 8);
//	t_vec	*sp_center6 = vec_default(4, 2, 10);
//	t_vec	*sp_center7 = vec_default(4, 4, 12);
//	t_vec	*sp_center8 = vec_default(2, 6, 10);
	int 	color_sp1 = creat_color(0, 255, 255);
	int 	color_sp2 = creat_color(0, 0, 255);
	int 	color_sp3 = creat_color(255, 0, 255);
	int 	color_sp4 = creat_color(7, 255, 0);
	int 	color_sp5 = creat_color(200, 255, 255);
//	int 	color_sp6 = creat_color(0, 0, 255);
//	int 	color_sp7 = creat_color(255, 0, 255);
//	int 	color_sp8 = creat_color(0, 255, 0);
	sp_list(&sps, sp_center1, 2, color_sp1);
	sp_list(&sps, sp_center2, 2, color_sp2);
	sp_list(&sps, sp_center3, 2, color_sp3);
	sp_list(&sps, sp_center4, 2, color_sp4);
	sp_list(&sps, sp_center5, 2, color_sp5);
//	sp_list(&sps, sp_center6, 2, color_sp6);
//	sp_list(&sps, sp_center7, 2, color_sp7);
//	sp_list(&sps, sp_center8, 2, color_sp8);
//	debug_sp(sps);

	t_tr	*trs = NULL;
//	t_vec	*tr1_p1 = vec_default(-2, -1, 6);
//	t_vec	*tr1_p2 = vec_default(4, 1, 6);
//	t_vec	*tr1_p3 = vec_default(0, 3, 6);
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
	t_vec	*v_p = vec_default(10, 20, 8);
	int		color_l1 = creat_color(255, 255, 255);
//	int		color_l2 = creat_color(255, 255, 255);
//	int		color_l3 = creat_color(255, 255, 255);
//	t_vec	*v_p1 = vec_default(0, 20, -6);
//	t_vec	*v_p2 = vec_default(0, 20, -10);
	l_list(&l, v_p, 1, color_l1);
//	l_list(&l, v_p1, 0.7, color_l2);
//	l_list(&l, v_p2, 0.7, color_l3);

	t_pl	*pls = NULL;
	t_vec	*crd1 = vec_default(0, -1, 0);
	t_vec	*pl_nrmd1 = vec_default(0, -1, 0);
	int		color_pl1 = creat_color(25, 99, 60);
//	t_vec	*crd2 = vec_default(-3, 0, 0);
//	t_vec	*pl_nrmd2 = vec_default(-1, 0, 0);
//	int		color_pl2 = creat_color(155, 99, 220);
//	t_vec	*crd3 = vec_default(0, 0, 50);
//	t_vec	*pl_nrmd3 = vec_default(0, 0, 1);
//	int		color_pl3 = creat_color(255, 59, 22);
	pl_list(&pls, crd1, pl_nrmd1, color_pl1);
//	pl_list(&pls, crd2, pl_nrmd2, color_pl2);
//	pl_list(&pls, crd3, pl_nrmd3, color_pl3);

	int		color_a = creat_color(255, 0, 0);
	t_a		*a = a_default(0.5, color_a);

	t_cam	*cams = NULL;
	t_vec	*cam_pos1 = vec_default(0, 0, -5);
	t_vec	*cam_direction1 = vec_default(0, 0, 1);
	cam_list(&cams, cam_pos1, cam_direction1, 60);
	t_sc	*sc = sc_default(cams, sps, trs, pls, l, a);
	sc->width = 900;
	sc->hight = 980;
	window = mlx_new_window(mlx, sc->width, sc->hight, "GOLOD");
	img.img = mlx_new_image(mlx, sc->width, sc->hight);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img
	.line_length, &img.endian);
//	printf("test\n");
	ray_tracing(&img, sc);
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	printf("READY!\n");
	mlx_loop(mlx);
	return (0);
}