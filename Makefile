NAME			=	minirt

INCLUDES		=	./includes/

SRCS			=	srcs/vector.c \
					srcs/camera.c \
					srcs/scene.c \
					srcs/data.c \
					srcs/sphere.c \
					srcs/ray_trace.c \
					srcs/main.c \
					srcs/screen.c \
					srcs/triangle.c \
					srcs/plane.c \
					srcs/square.c \
					srcs/light.c \
					srcs/lightning.c \
					srcs/ambient_lightning.c \
					srcs/color.c \
					srcs/ray_sphere_intersection.c \
					srcs/ray_triangle_intersection.c \
					srcs/ray_plane_intersection.c \
					srcs/closest_objects.c \
					srcs/keys.c \
					srcs/all.c \
					srcs/parsing.c \
					srcs/parsing_objs.c \
					srcs/char_to.c \
					srcs/get_next_line/get_next_line.c \
					srcs/get_next_line/get_next_line_utils.c \
					srcs/rotate_camera.c \
					srcs/bmp_file.c \

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