SRC		=	main.c  get_next_line.c get_next_line_outils.c 

main: main.c
	$(CC)  $(SRC) -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror