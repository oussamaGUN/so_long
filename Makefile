SRC = main.c get_next_line/get_next_line.c get_next_line/get_next_line_outils.c \
      check_error/check_1.c check_error/check_2.c check_error/flood_fill.c check_error/flood_fill2.c \
      maps_render/map_rendering.c maps_render/render_object.c maps_render/animation.c \
      key_hook/key_hook.c key_hook/key_hook_events.c key_hook/functions.c \
      tools/tools_1.c tools/tools_2.c tools/tools3.c

OBJC = $(SRC:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJC)
	gcc $(OBJC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	gcc -c $< -o $@   -D BUFFER_SIZE=1

clean:
	rm -rf $(OBJC)

fclean: clean
	rm -rf $(NAME)

re: fclean all
