SRC		=	main.c  get_next_line/get_next_line.c get_next_line/get_next_line_outils.c check_error/check_1.c check_error/check_2.c

main: main.c
	$(CC)  $(SRC) -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror