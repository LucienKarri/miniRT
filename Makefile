NAME			=	minirt

INCLUDES		=	./includes/

SRCS			=	srcs/vector.c \
					srcs/vector1.c \
					srcs/elements/camera.c \
					srcs/scene.c \
					srcs/data.c \
					srcs/elements/sphere.c \
					srcs/ray_trace.c \
					minirt.c \
					srcs/screen.c \
					srcs/elements/triangle.c \
					srcs/elements/plane.c \
					srcs/elements/square.c \
					srcs/elements/light.c \
					srcs/elements/cylinder.c \
					srcs/lightning.c \
					srcs/elements/ambient_lightning.c \
					srcs/color.c \
					srcs/intersections/ray_sphere_intersection.c \
					srcs/intersections/ray_triangle_intersection.c \
					srcs/intersections/ray_plane_intersection.c \
					srcs/intersections/ray_square_intersection.c \
					srcs/intersections/ray_cylinder_intersection.c \
					srcs/closest_objects.c \
					srcs/close_inter.c \
					srcs/keys.c \
					srcs/all.c \
					srcs/parse/parsing.c \
					srcs/parse/parsing_objs.c \
					srcs/parse/parsing_elems.c \
					srcs/char_to.c \
					srcs/get_next_line.c \
					srcs/get_next_line_utils.c \
					srcs/elements/rotate_camera.c \
					srcs/bmp_file.c \
					srcs/error_and_exit.c \
					srcs/ft_strcmp.c \

OBJS			=	${SRCS:.c=.o}

MLX				=	mlx_linux/*.a

CC				=	gcc

CFLAGS			=	-Wall  -Wextra -g

LFLAGS			=	-Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -lbsd

RM				=	rm -rf

.c.o:
				${CC} ${CFLAGS} -I ${INCLUDES} -Imlx_linux -O3 -c $< -o ${<:.c=.o}

all:			${NAME}

${NAME}:		${OBJS}
						${CC} ${CFLAGS} -I ${INCLUDES} ${OBJS} -L ${MLX} ${LFLAGS} -o ${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
						${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re