SRC		=	main.c  get_next_line/get_next_line.c get_next_line/get_next_line_outils.c check_error/check_1.c check_error/check_2.c \
			maps_render/map_rendering.c maps_render/render_object.c

main: main.c
	$(CC)  $(SRC) -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror