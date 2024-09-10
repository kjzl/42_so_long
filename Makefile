NAME = so_long
CFLAGS = -Wall -Wextra -Werror -O3
# CFLAGS = -g -Og

LIBFTDIR = ./libft
MLXDIR = ./minilibx

SRCS = \
	src/so_long.c\
	src/win.c\
	src/parse/validate.c\
	src/parse/parse.c\
	src/sprite/assets.c\
	src/sprite/player.c\
	src/sprite/player2.c\
	src/loop/cam.c\
	src/loop/input.c\
	src/mlximg/mlximg.c\
	src/util/level.c\
	src/render/render_level.c\
	src/render/render_objects.c\
	src/mlximg/mlximg2.c\
	src/render/render.c\
	src/loop/collision.c\
	src/util/pos.c\
	src/util/tile.c\
	src/util/level_info.c\
	src/util/action.c\
	src/util/coins.c\
	src/util/asset.c\
	src/util/player.c\

OBJ = $(SRCS:.c=.o)

%.o: %.c
	cc $(CFLAGS) -c -I$(LIBFTDIR) -I$(MLXDIR) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR) CFLAGS='$(CFLAGS)'
	$(MAKE) -C $(MLXDIR)
	cc $(CFLAGS) $(OBJ) -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx -lXext -lX11 -lm -o $(NAME)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
